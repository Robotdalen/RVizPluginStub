#include <QtGui>
#include <QVBoxLayout>
#include <QPushButton>


#include <rviz/panel.h>
#include <ros/ros.h>

class PluginPanel: public rviz::Panel
{
    Q_OBJECT

public:
    PluginPanel(QWidget* parent = 0);


    public Q_SLOTS:
      void startPolygon();
      void polygonDone();

      
protected:
    QVBoxLayout* _vbox;

    QPushButton* _button1;
    QPushButton* _button2;

    ros::NodeHandle _nh;
    ros::Publisher _startPolygonPublisher;
    ros::Publisher _polygonDonePublisher;
};
