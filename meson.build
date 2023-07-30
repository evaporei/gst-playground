project('gst-playground', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

# gobject = dependency('gobject-2.0')
# glib = dependency('glib-2.0')
gstreamer = dependency('gstreamer-1.0') 
gstreamer_video = dependency('gstreamer-video-1.0')
gtk = dependency('gtk+-3.0')

executable('basic-tutorial-1', 'basic-tutorial-1.c', dependencies : gstreamer)
executable('basic-tutorial-2', 'basic-tutorial-2.c', dependencies : gstreamer)
executable('basic-tutorial-3', 'basic-tutorial-3.c', dependencies : gstreamer)
executable('basic-tutorial-4', 'basic-tutorial-4.c', dependencies : gstreamer)
executable('basic-tutorial-5', 'basic-tutorial-5.c', dependencies : [gstreamer, gstreamer_video, gtk])
executable('basic-tutorial-6', 'basic-tutorial-6.c', dependencies : gstreamer)
executable('basic-tutorial-7', 'basic-tutorial-7.c', dependencies : gstreamer)
