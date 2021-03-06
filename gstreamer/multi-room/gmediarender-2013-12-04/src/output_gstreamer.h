/* output_gstreamer.h - Definitions for GStreamer output module
 *
 * Copyright (C) 2005-2007   Ivo Clarysse
 *
 * This file is part of GMediaRender.
 *
 * GMediaRender is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GMediaRender is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GMediaRender; if not, write to the Free Software 
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, 
 * MA 02110-1301, USA.
 *
 */

#ifndef _OUTPUT_GSTREAMER_H
#define _OUTPUT_GSTREAMER_H

#define MEDIA_PORT 1500
#define CONTROL_PORT 1501

#define TRANS_TYPE_TCP 0
#define TRANS_TYPE_RTP 1
#define TRANS_TYPE TRANS_TYPE_RTP

typedef struct{
  	GstElement *source;
	GstElement *tee;
	gint clock_port;
}GstData;

extern struct output_module gstreamer_output;
extern GstData gst_data;
extern GstElement *player_;
extern GstElement *player2_;
extern gchar *audio_sink;
extern gchar *audio_device;
extern gchar *videosink;

int output_gstreamer_init_master(void);
int output_gstreamer_init_master2(void);
int output_gstreamer_init_master3(void);
int output_gstreamer_init_slave(void);
int output_gstreamer_control_init_slave(void);
void output_gstreamer_pipeline_init_slave(GstElement *player, gchar* ip_addr);
void send_cmd_to_server(gchar *cmd);
int add_slave_to_pipeline(char* ip_addr);
int add_slave_to_control(struct UpDeviceNode *devnode);
gboolean my_bus_callback(GstBus * bus, GstMessage * msg, gpointer data);
gboolean my_bus_callback2(GstBus * bus, GstMessage * msg, gpointer data);
void pad_added_handler (GstElement *src, GstPad *new_pad, gpointer data);

#endif /*  _OUTPUT_GSTREAMER_H */
