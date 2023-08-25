/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// 3 displays:
#define ST7789_NUM_DEVICES 1

/* SPI settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
// We don't actually use MISO, so set it to a pin we don't use.
// Otherwise it likely get's tripped up as we use GP16 for D/C
#define SPI_MISO_PIN GP16

#define DISPLAY_CS_PIN GP17
#define DISPLAY_RST_PIN GP24
#define DISPLAY_DC_PIN GP23
#define DISPLAY_BL_PIN GP22