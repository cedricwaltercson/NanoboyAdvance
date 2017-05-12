/**
  * Copyright (C) 2017 flerovium^-^ (Frederic Meyer)
  *
  * This file is part of NanoboyAdvance.
  *
  * NanoboyAdvance is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  * 
  * NanoboyAdvance is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  * 
  * You should have received a copy of the GNU General Public License
  * along with NanoboyAdvance. If not, see <http://www.gnu.org/licenses/>.
  */

#pragma once

#include "enums.hpp"
#include "util/integer.hpp"
#include "../cpu/interrupt.hpp"
#include "../config.hpp"

#define PPU_INCLUDE

namespace GameBoyAdvance {
    
    const u16 COLOR_TRANSPARENT = 0x8000;

    class PPU {
    private:
        u8* m_pal;
        u8* m_oam;
        u8* m_vram;
        Interrupt* m_interrupt = nullptr;
        
        int  m_frameskip;
        u32* m_framebuffer;
        Config* m_config;

        // rendering buffers
        u16  m_buffer[4][240];
        bool m_win_mask[2][240];
        
        // color conversion LUT
        u32 m_color_lut[0x8000];
        
        struct ObjectPixel {
            u8  prio;
            u16 pixel;
            bool alpha;
            bool window;
        } m_obj_layer[240];

        int m_frame_counter;

        #include "io.hpp"
        #include "helpers.hpp"

        void render_text(int id);
        void render_affine(int id);
        void render_bitmap_1();
        void render_bitmap_2();
        void render_bitmap_3();
        void render_obj(u32 tile_base);
        
        void apply_sfx(u16* target1, u16 target2, SpecialEffect sfx);
        
    public:
        PPU(Config* config);

        void reset();
        void load_config();
        
        IO& get_io() {
            return m_io;
        }

        void set_memory(u8* pal, u8* oam, u8* vram);
        void set_interrupt(Interrupt* interrupt);

        void hblank();
        void vblank();
        void scanline(bool render);
        void next_line();
        
        void render_window(int id);

        void compose_scanline();
    };
}

#undef PPU_INCLUDE