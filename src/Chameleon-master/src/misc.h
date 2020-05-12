/*
  Chameleon, a UCI Chinese Chess (also called Xiangqi) engine derived from Stockfish 7
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright (C) 2015-2017 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad
  Copyright (C) 2017 Wilbert Lee

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef MISC_H_INCLUDED
#define MISC_H_INCLUDED

#include <cassert>
#include <chrono>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

#include "types.h"

enum SyncCout
{
  IO_LOCK,
  IO_UNLOCK
};

typedef std::chrono::milliseconds::rep TimePoint; // A value in milliseconds

void prefetch(void *addr);
void start_logger(bool b);
void dbg_hit_on(bool b);
void dbg_hit_on(bool c, bool b);
void dbg_mean_of(int v);
void dbg_print();
const std::string engine_info(bool to_uci = false);

inline TimePoint now()
{
  return std::chrono::duration_cast<std::chrono::milliseconds>
         (std::chrono::steady_clock::now().time_since_epoch()).count();
}

struct Log : public std::ofstream
{
  Log(const std::string &f = "log.txt") : std::ofstream(f.c_str(), std::ios::out | std::ios::app)  {}
  ~Log()
  {
    if (is_open()) close();
  }
};

template<class Entry, int Size>
struct HashTable
{
  Entry *operator[](Key key)
  {
    return &table[(uint32_t)key & (Size - 1)];
  }
private:
  std::vector<Entry> table = std::vector<Entry>(Size);
};

std::ostream &operator<<(std::ostream &, SyncCout);

#define sync_cout std::cout << IO_LOCK
#define sync_endl std::endl << IO_UNLOCK

// xorshift64star Pseudo-Random Number Generator
// This class is based on original code written and dedicated
// to the public domain by Sebastiano Vigna (2014).
// It has the following characteristics:
//
//  -  Outputs 64-bit numbers
//  -  Passes Dieharder and SmallCrush test batteries
//  -  Does not require warm-up, no zeroland to escape
//  -  Internal state is a single 64-bit integer
//  -  Period is 2^64 - 1
//  -  Speed: 1.60 ns/call (Core i7 @3.40GHz)
//
// For further analysis see
//   <http://vigna.di.unimi.it/ftp/papers/xorshift.pdf>

class PRNG
{
  Key s;

  Key rand64()
  {
    s ^= s >> 12, s ^= s << 25, s ^= s >> 27;
    return s * 2685821657736338717LL;
  }

public:
  PRNG(Key seed) : s(seed)
  {
    assert(seed);
  }

  template<typename T> T rand()
  {
    return T(rand64());
  }

  // Special generator used to fast init magic numbers.
  // Output values only have 1/8th of their bits set on average.
  template<typename T> T sparse_rand()
  {
    return T(rand64() & rand64() & rand64());
  }
};

#endif // #ifndef MISC_H_INCLUDED
