/*
 * EEZ Modular Firmware
 * Copyright (C) 2015-present, Envox d.o.o.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <eez/gui/font.h>
#include <eez/gui/widget.h>

namespace eez {
namespace gui {

font::Font styleGetFont(const Style *style);
bool styleIsBlink(const Style *style);

void drawText(const char *text, int textLength, int x, int y, int w, int h, const Style *style,
              const Style *activeStyle, bool active, bool blink, bool ignoreLuminocity,
              uint16_t *overrideBackgroundColor);

void drawMultilineText(const char *text, int x, int y, int w, int h, const Style *style,
                       const Style *activeStyle, bool active, int firstLineIndent, int hangingIndent);

void drawBitmap(void *bitmapPixels, int bpp, int bitmapWidth, int bitmapHeight, int x, int y, int w,
                int h, const Style *style, const Style *activeStyle, bool active);

void drawRectangle(int x, int y, int w, int h, const Style *style, const Style *activeStyle,
                   bool active, bool ignoreLuminocity);

void drawShadow(int x1, int y1, int x2, int y2);

} // namespace gui
} // namespace eez
