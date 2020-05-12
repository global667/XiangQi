/*
 * Copyright 2015-2018 the original author or authors.
 *
 * All rights reserved. This program and the accompanying materials are
 * made available under the terms of the Eclipse Public License v2.0 which
 * accompanies this distribution and is available at
 *
 * http://www.eclipse.org/legal/epl-v20.html
 */

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

class MousePressTests {

	@Test
	@DisplayName("MousePressed")
	void mousePressed() {
		XiangQi xiangqi = new XiangQi();
		//for (int i = 0; i<=90; i++)
			assertEquals(0, xiangqi.mousePressedX(0), "Sollte die richtigen Koordinaten darstellen");
		assertEquals(0, xiangqi.mousePressedX(80), "Sollte die richtigen Koordinaten darstellen");
	}

	@ParameterizedTest(name = "{0} = {1}")
	@CsvSource({
			"0,    0",
			"1,    0",
			"44,   0",
			"45,   0",
			"48,   0",
			"51,   0",
			"60,   0",
			"90,   0",
			"110,  1",
			"150,  1",
			"200,  2"
	})
	void mousePressedX(int first, int expectedResult) {
		XiangQi xiangqi = new XiangQi();
		assertEquals(expectedResult, xiangqi.mousePressedX(first),
				() -> first + " should equal " + expectedResult);
	}
	@ParameterizedTest(name = "{0} = {1}")
	@CsvSource({
			"0,    0",
			"1,    0",
			"44,   0",
			"45,   0",
			"48,   0",
			"51,   0",
			"60,   0",
			"90,   0",
			"110,  1",
			"150,  1",
			"200,  2"
	})
	void mousePressedY(int first, int expectedResult) {
		XiangQi xiangqi = new XiangQi();
		assertEquals(expectedResult, xiangqi.mousePressedY(first),
				() -> first + " should equal " + expectedResult);
	}
}






