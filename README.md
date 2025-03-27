Fork of GLFX for continued use in [Met.3D](https://gitlab.com/wxmetvis/met.3d)
This is a specialized fork for use with Met.3D and probably won't work in other contexts.

It changes order in which effect files are put together, so that extension directives are supported.

It removes the GLEW dependency and replaces it with [Qt GUI](https://doc.qt.io/qt-5/qtgui-index.html).
This was required to update Met.3D to use the same module for OpenGL rendering.
Only the cmake file was adjusted to reflect this dependency change.