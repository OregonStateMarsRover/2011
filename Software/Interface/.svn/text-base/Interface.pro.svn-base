QT += core \
        gui \
        opengl
#   phonon
TARGET = Interface
TEMPLATE = app
SOURCES += main.cpp \
	GUI/MainWindow.cpp \
	GUI/DriveWidget.cpp \
	GUI/ArmWidget.cpp \
	GUI/CameraWidget.cpp \
	GUI/StatusWidget.cpp \
	GUI/NavigationWidget.cpp \
	GUI/NavigationView.cpp \
	GUI/NavigationPlace.cpp \
	GUI/NavigationRover.cpp \
	GUI/TriangulationWidget.cpp \
	GUI/TriangulationInputLine.cpp \
	GUI/ScienceWidget.cpp \
	GUI/ScienceSite.cpp \
#   GUI/VideoWidget.cpp \
	VirtualRover/AbstractController.cpp \
        VirtualRover/RobotController.cpp \
	VirtualRover/ArmController.cpp \
	VirtualRover/TripodController.cpp \
	VirtualRover/SensorController.cpp \
	../Common/CommInterface/SerialProtocol.c \
	Wireless/WirelessDispatcher.cpp \
	Wireless/WirelessPacket.cpp \
	Common/Configuration.cpp \
        Common/Matrix.cpp \
    GUI/IntersectionLineItem.cpp \
    Tactile/TactileInterface.cpp \
    Tactile/Joystick.cpp \
    VirtualRover/MotorController.cpp \
    VirtualRover/GPSController.cpp \
    Wireless/SerialDevice.cpp \
    VirtualRover/StatusController.cpp \
    GUI/ArmGLWidget.cpp \
    GUI/NavigationPlaceDialog.cpp \
    GUI/TriangulationSidebar.cpp \
    Common/USBDevice.cpp \
    Tactile/BaseBarometer.cpp \
    Common/AltitudeCalculator.cpp
HEADERS += GUI/MainWindow.h \
	GUI/DriveWidget.h \
	GUI/ArmWidget.h \
	GUI/CameraWidget.h \
	GUI/StatusWidget.h \
	GUI/NavigationWidget.h \
	GUI/NavigationView.h \
	GUI/NavigationPlace.h \
	GUI/NavigationRover.h \
	GUI/TriangulationWidget.h \
	GUI/TriangulationInputLine.h \
	GUI/ScienceWidget.h \
	GUI/ScienceSite.h \
#	GUI/VideoWidget.h \
	VirtualRover/AbstractController.h \
        VirtualRover/RobotController.h \
	VirtualRover/ArmController.h \
	VirtualRover/TripodController.h \
	VirtualRover/SensorController.h \
	../Common/CommInterface/SerialProtocol.h \
	Wireless/WirelessDispatcher.h \
	Wireless/WirelessPacket.h \
	Common/Configuration.h \
        Common/Matrix.h \
    GUI/IntersectionLineItem.h \
    Tactile/TactileInterface.h \
    Tactile/Joystick.h \
    VirtualRover/MotorController.h \
    VirtualRover/GPSController.h \
    Wireless/SerialDevice.h \
    VirtualRover/StatusController.h \
    GUI/ArmGLWidget.h \
    GUI/NavigationPlaceDialog.h \
    GUI/TriangulationSidebar.h \
    Common/USBDevice.h \
    Tactile/BaseBarometer.h \
    Common/AltitudeCalculator.h
FORMS += GUI/Forms/DriveWidget.ui \
	GUI/Forms/ArmWidget.ui \
	GUI/Forms/CameraWidget.ui \
	GUI/Forms/StatusWidget.ui \
	GUI/Forms/NavigationWidget.ui \
	GUI/Forms/TriangulationWidget.ui \
	GUI/Forms/ScienceWidget.ui \
	GUI/Forms/VideoWidget.ui \
    GUI/Forms/NavigationPlaceDialog.ui \
    GUI/TriangulationSidebar.ui
RESOURCES += GUI/Resources/Icons/Icons.qrc \
	GUI/Resources/Maps/Maps.qrc
INCLUDEPATH += ../Common/CommInterface/
