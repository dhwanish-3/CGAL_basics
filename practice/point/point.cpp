#include <iostream>                         // cpp header
#include <QtGui>                            // QT header for GUI
#include <QApplication>                     // QT header for creating a QT GUI application
#include <QGraphicsScene>                   // QT header for 2D graphical items
#include <QGraphicsView>                    // QT header for displaying the contents of a scene
#include <CGAL/Qt/GraphicsViewNavigation.h> //CGAL header for linking CGAL and QGraphicsView 

int main(int argc, char **argv)
{
    QApplication app(argc, argv);       // create a new QT GUI application
    QGraphicsScene scene;               // create a QT scene to display point
    scene.setSceneRect(0, 0, 500, 300); // set scene size

    // add a point in the scene
    scene.addEllipse(100, 100, 5, 5);
    // display the scene
    QGraphicsView *view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);
    view->show();
    return app.exec();
}