#include <stdio.h>
#include <gst/gst.h>
#include <glib.h>

int
tutorial_main (int argc, char *argv[])
{
  printf("is initialized? %d\n", gst_is_initialized()); // 0

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  printf("executable path: %s\n", gst_get_main_executable_path()); // /home/rei/gst-playground/basic-tutorial-1
  printf("is initialized? %d\n", gst_is_initialized()); // 1
  printf("version string: %s\n", gst_version_string()); // GStreamer 1.22.1

  guint major, minor, micro, nano;

  gst_version(&major, &minor, &micro, &nano);

  printf("major: %d, minor: %d, micro: %d, nano: %d\n", major, minor, micro, nano); // 1, 22, 1, 0

  printf("%d\n", gst_segtrap_is_enabled()); // 1, enabled by default

  /* Build the pipeline */
  pipeline =
      gst_parse_launch
      ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
      NULL);

  gchar *name = gst_element_get_name(pipeline);
  printf("namae: %s\n", name); // playbin0
  g_free(name);

  /* Start playing */
  GstStateChangeReturn state = gst_element_set_state (pipeline, GST_STATE_PLAYING);

  printf("state: %d\n", state); // 2, async (docs: https://gstreamer.freedesktop.org/documentation/gstreamer/gstelement.html?gi-language=c#GstStateChangeReturn)

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* See next tutorial for proper error message handling/parsing */
  if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
    g_error ("An error occurred! Re-run with the GST_DEBUG=*:WARN environment "
        "variable set for more details.");
  }

  /* Free resources */
  gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
  return 0;
}

int
main (int argc, char *argv[])
{
  return tutorial_main (argc, argv);
}
