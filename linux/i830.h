/* i830.h -- Intel I830 DRM template customization -*- linux-c -*-
 * Created: Thu Feb 15 00:01:12 2001 by gareth@valinux.com
 *
 * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    Gareth Hughes <gareth@valinux.com>
 */

#ifndef __I830_H__
#define __I830_H__

/* This remains constant for all DRM template files.
 */
#define DRM(x) i830_##x

/* General customization:
 */
#define __HAVE_AGP		1
#define __MUST_HAVE_AGP		1
#define __HAVE_MTRR		1
#define __HAVE_CTX_BITMAP	1

#define DRIVER_AUTHOR		"VA Linux Systems Inc."

#define DRIVER_NAME		"i830"
#define DRIVER_DESC		"Intel 830M"
#define DRIVER_DATE		"20020828"

#define DRIVER_MAJOR		1
#define DRIVER_MINOR		2
#define DRIVER_PATCHLEVEL	1

#define DRIVER_IOCTLS							    \
	[DRM_IOCTL_NR(DRM_IOCTL_I830_INIT)]   = { i830_dma_init,    1, 1 }, \
   	[DRM_IOCTL_NR(DRM_IOCTL_I830_VERTEX)] = { i830_dma_vertex,  1, 0 }, \
   	[DRM_IOCTL_NR(DRM_IOCTL_I830_CLEAR)]  = { i830_clear_bufs,  1, 0 }, \
      	[DRM_IOCTL_NR(DRM_IOCTL_I830_FLUSH)]  = { i830_flush_ioctl, 1, 0 }, \
   	[DRM_IOCTL_NR(DRM_IOCTL_I830_GETAGE)] = { i830_getage,      1, 0 }, \
	[DRM_IOCTL_NR(DRM_IOCTL_I830_GETBUF)] = { i830_getbuf,      1, 0 }, \
   	[DRM_IOCTL_NR(DRM_IOCTL_I830_SWAP)]   = { i830_swap_bufs,   1, 0 }, \
   	[DRM_IOCTL_NR(DRM_IOCTL_I830_COPY)]   = { i830_copybuf,     1, 0 }, \
   	[DRM_IOCTL_NR(DRM_IOCTL_I830_DOCOPY)] = { i830_docopy,      1, 0 },

#define __HAVE_COUNTERS         4
#define __HAVE_COUNTER6         _DRM_STAT_IRQ
#define __HAVE_COUNTER7         _DRM_STAT_PRIMARY
#define __HAVE_COUNTER8         _DRM_STAT_SECONDARY
#define __HAVE_COUNTER9         _DRM_STAT_DMA

/* Driver customization:
 */
#define __HAVE_RELEASE		1
#define DRIVER_RELEASE() do {						\
	i830_reclaim_buffers( dev, priv->pid );				\
} while (0)

/* DMA customization:
 */
#define __HAVE_DMA		1
#define __HAVE_DMA_QUEUE	1
#define __HAVE_DMA_WAITLIST	1
#define __HAVE_DMA_RECLAIM	1

#define __HAVE_DMA_QUIESCENT	1
#define DRIVER_DMA_QUIESCENT() do {					\
	i830_dma_quiescent( dev );					\
} while (0)

/* Don't need an irq any more.  The template code will make sure that
 * a noop stub is generated for compatibility.
 */
#define __HAVE_DMA_IRQ		0

/* Buffer customization:
 */

#define DRIVER_BUF_PRIV_T	drm_i830_buf_priv_t

#define DRIVER_AGP_BUFFERS_MAP( dev )					\
	((drm_i830_private_t *)((dev)->dev_private))->buffer_map

#endif
