#include <pluginlib/class_list_macros.h>

#include "plugin_panel.h"
#include "std_msgs/Empty.h"

PluginPanel::PluginPanel(QWidget* parent):
    rviz::Panel(parent)
{
    _vbox = new QVBoxLayout();

    _button1 = new QPushButton(tr("Button 1"));
    _button2 = new QPushButton(tr("Button 2"));

    _button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _button1->setText("Start polygon");
    _button2->setText("Polygon done");

    _vbox->addWidget(_button1);
    _vbox->addWidget(_button2);

    setLayout(_vbox);

    connect(_button1, SIGNAL(released()), this, SLOT(startPolygon()));
    connect(_button2, SIGNAL(released()), this, SLOT(polygonDone()));

    //ros::init(argc, argv, "plugin_panel");

    _startPolygonPublisher = _nh.advertise<std_msgs::Empty>("startPolygon", 1);
    _polygonDonePublisher = _nh.advertise<std_msgs::Empty>("polygonDone", 1);
}

void PluginPanel::startPolygon() {
  //  ROS_WARN("Pushed button 1");
  std_msgs::Empty msg;
  _startPolygonPublisher.publish(msg);
}
void PluginPanel::polygonDone() {
  std_msgs::Empty msg;
  _polygonDonePublisher.publish(msg);
}



// How to connect the buttons to a function?

// One button for starting a new polygon
// One button for saying polygon is done
// These two messges should be received in the create polygon node

PLUGINLIB_EXPORT_CLASS(PluginPanel, rviz::Panel)
