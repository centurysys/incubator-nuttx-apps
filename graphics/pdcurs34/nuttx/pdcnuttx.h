/****************************************************************************
 * apps/graphics/nuttx/pdcnuttx.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __APPS_GRAPHICS_PDCURS34_NUTTX_PDCNUTTX_H
#define __APPS_GRAPHICS_PDCURS34_NUTTX_PDCNUTTX_H 1

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "nuttx/config.h"

#include <stdint.h>

#include "nuttx/nx/nx.h"
#include "nuttx/nx/nxfonts.h"
#include <nuttx/video/fb.h>
#include <nuttx/video/rgbcolors.h>

#include "curspriv.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#undef HAVE_BOLD_FONT

#if defined(CONFIG_PDCURSES_FONT_4X6)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_4X6
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_4X6
#elif defined(CONFIG_PDCURSES_FONT_5X7)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_5X7
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_5X7
#elif defined(CONFIG_PDCURSES_FONT_5X8)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_5X8
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_5X8
#elif defined(CONFIG_PDCURSES_FONT_6X9)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_6X9
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_6X9
#elif defined(CONFIG_PDCURSES_FONT_6X10)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_6X10
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_6X10
#elif defined(CONFIG_PDCURSES_FONT_6X12)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_6X12
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_6X12
#elif defined(CONFIG_PDCURSES_FONT_6X13)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_6X13
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_6X13B
#  define HAVE_BOLD_FONT        1
#elif defined(CONFIG_PDCURSES_FONT_7X13)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_7X13
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_7X13B
#  define HAVE_BOLD_FONT        1
#elif defined(CONFIG_PDCURSES_FONT_7X14)
#  define PDCURSES_FONTID       FONTID_X11_MISC_FIXED_7X14
#  define PDCURSES_BOLD_FONTID  FONTID_X11_MISC_FIXED_7X14B
#  define HAVE_BOLD_FONT        1
#elif defined(CONFIG_PDCURSES_FONT_8X13)
#  define PDCURSES_FONTID        FONTID_X11_MISC_FIXED_8X13
#  define PDCURSES_BOLD_FONTID   FONTID_X11_MISC_FIXED_8X13B
#  define HAVE_BOLD_FONT        1
#elif defined(CONFIG_PDCURSES_FONT_9X15)
#  define PDCURSES_FONTID        FONTID_X11_MISC_FIXED_9X15
#  define PDCURSES_FONTID        FONTID_X11_MISC_FIXED_9X15B
#  define HAVE_BOLD_FONT        1
#elif defined(CONFIG_PDCURSES_FONT_9X18)
#  define PDCURSES_FONTID        FONTID_X11_MISC_FIXED_9X18
#  define PDCURSES_BOLD_FONTID   FONTID_X11_MISC_FIXED_9X18B
#  define HAVE_BOLD_FONT        1
#elif defined(CONFIG_PDCURSES_FONT_10X20)
#  define PDCURSES_FONTID        FONTID_X11_MISC_FIXED_10X20
#  define PDCURSES_BOLD_FONTID   FONTID_X11_MISC_FIXED_10X20
#else
#  error No fixed width font selected
#endif

#if defined(CONFIG_PDCURSES_COLORFMT_Y1)
#  warning CONFIG_PDCURSES_COLORFMT_Y1 not yet supported
#  define PDCURSES_COLORFMT      FB_FMT_Y1
#  define PDCURSES_BPP           1
#elif defined(CONFIG_PDCURSES_COLORFMT_RGB332)
#  define PDCURSES_COLORFMT      FB_FMT_RGB8_332
#  define PDCURSES_BPP           8
#  define PDCURSES_BPP_MASK      7
#  define PDCURSES_BPP_SHIFT     3
#elif defined(CONFIG_PDCURSES_COLORFMT_RGB565)
#  define PDCURSES_COLORFMT      FB_FMT_RGB16_565
#  define PDCURSES_BPP           16
#  define PDCURSES_BPP_MASK      15
#  define PDCURSES_BPP_SHIFT     4
#elif defined(CONFIG_PDCURSES_COLORFMT_RGB888)
#  define PDCURSES_COLORFMT      FB_FMT_RGB24  /* RGB24 at 32-BPP */
#  define PDCURSES_BPP           32
#  define PDCURSES_BPP_MASK      31
#  define PDCURSES_BPP_SHIFT     5
#else
#  error No color format selected
#endif

/* Select renderer -- Some additional logic would be required to support
 * pixel depths that are not directly addressable (1,2,4, and 24).
 */

#if PDCURSES_BPP == 1
#  define RENDERER nxf_convert_1bpp
#elif PDCURSES_BPP == 2
#  define RENDERER nxf_convert_2bpp
#elif PDCURSES_BPP == 4
#  define RENDERER nxf_convert_4bpp
#elif PDCURSES_BPP == 8
#  define RENDERER nxf_convert_8bpp
#elif PDCURSES_BPP == 16
#  define RENDERER nxf_convert_16bpp
#elif PDCURSES_BPP == 24
#  define RENDERER nxf_convert_24bpp
#elif PDCURSES_BPP == 32
#  define RENDERER nxf_convert_32bpp
#else
#  error "Unsupported bits-per-pixel"
#endif

/* Convert bits to bytes to hold an even number of pixels */

#define PDCURSES_ALIGN_UP(n)   (((n) + PDCURSES_BPP_MASK) >> 3)
#define PDCURSES_ALIGN_DOWN(n) (((n) & ~PDCURSES_BPP_MASK) >> 3)

/****************************************************************************
 * Private Types
 ****************************************************************************/

#if defined(__cplusplus)
extern "C"
{
#  define EXTERN extern "C"
#else
#  define EXTERN extern
#endif

/* Describes one color pair */

struct pdc_colorpair_s
{
  short fg;
  short bg;
};

/* Describes one RGB color */

struct pdc_rgbcolor_s
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

/* Holds one framebuffer pixel */

#if defined(CONFIG_PDCURSES_COLORFMT_RGB332)
typedef uint8_t  pdc_color_t;
#elif defined(CONFIG_PDCURSES_COLORFMT_RGB565)
typedef uint16_t pdc_color_t;
#elif defined(CONFIG_PDCURSES_COLORFMT_RGB888)
typedef uint32_t pdc_color_t;
#endif

/* This structure provides the overall state of the frambuffer device */

struct pdc_fbstate_s
{
  /* Framebuffer */

  int fd;                /* Open framebuffer driver file descriptor */
  FAR void *fbmem;       /* Start of framebuffer memory */
  fb_coord_t xres;       /* Horizontal resolution (pixels) */
  fb_coord_t yres;       /* Vertical resolution (rows) */
  fb_coord_t stride;     /* Length of a line (bytes) */

  /* Font */

  NXHANDLE hfont;        /* Handled uses to access selected font */
#ifdef HAVE_BOLD_FONT
  NXHANDLE hbold;        /* Handled uses to access bold font */
#endif
  uint8_t fheight;       /* Height of the font (rows) */
  uint8_t fwidth;        /* Width of the font (pixels) */

  /* Drawable area (See also SP->lines and SP->cols) */

  fb_coord_t xpos;       /* Drawing X position (pixels) */
  fb_coord_t ypos;       /* Drawing Y position (rows) */
  uint8_t hoffset;       /* Offset from left of display (pixels) */
  uint8_t voffset;       /* Offset from top of display (rows) */

  /* Colors */

  struct pdc_colorpair_s colorpair[PDC_COLOR_PAIRS];
  struct pdc_rgbcolor_s rgbcolor[16];
};

/* This structure contains the framebuffer device structure and is a cast
 * compatible with type SCREEN.
 */

struct pdc_fbscreen_s
{
  SCREEN screen;
  struct pdc_fbstate_s fbstate;
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* This singleton represents the state of frame buffer device.  pdcurses
 * depends on global variables and, hence, can never support more than a
 * single framebuffer instance in the same address space.
 */

EXTERN struct pdc_fbstate_s g_pdc_fbstate;

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __APPS_GRAPHICS_PDCURS34_NUTTX_PDCNUTTX_H */
