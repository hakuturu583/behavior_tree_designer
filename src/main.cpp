// Headers in NodeEditor
#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>
#include <nodes/ConnectionStyle>
#include <nodes/TypeConverter>

using QtNodes::DataModelRegistry;
using QtNodes::FlowScene;
using QtNodes::FlowView;
using QtNodes::ConnectionStyle;
using QtNodes::TypeConverter;
using QtNodes::TypeConverterId;

// Headers in Qt
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenuBar>

// Headers in this package
#include <behavior_tree_designer/root_node.h>

static void setStyle()
{
  ConnectionStyle::setConnectionStyle(
  R"(
  {
    "ConnectionStyle": {
      "ConstructionColor": "gray",
      "NormalColor": "black",
      "SelectedColor": "gray",
      "SelectedHaloColor": "deepskyblue",
      "HoveredColor": "deepskyblue",

      "LineWidth": 3.0,
      "ConstructionLineWidth": 2.0,
      "PointDiameter": 10.0,

      "UseDataDefinedColors": true
    }
  }
  )");
}

static std::shared_ptr<DataModelRegistry> registerDataModels()
{
    auto ret = std::make_shared<DataModelRegistry>();
    ret->registerModel<RootNodeDataModel>("RootNode");
    return ret;
}

void validation()
{
    
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    setStyle();
    QWidget mainWidget;
    auto menuBar    = new QMenuBar();
    auto saveAction = menuBar->addAction("Save..");
    auto loadAction = menuBar->addAction("Load..");
    auto validationAction = menuBar->addAction("Validation..");
    QVBoxLayout *l = new QVBoxLayout(&mainWidget);
    l->addWidget(menuBar);
    auto scene = new FlowScene(registerDataModels(), &mainWidget);
    l->addWidget(new FlowView(scene));
    l->setContentsMargins(0, 0, 0, 0);
    l->setSpacing(0);
    QObject::connect(saveAction, &QAction::triggered,scene, &FlowScene::save);
    QObject::connect(loadAction, &QAction::triggered,scene, &FlowScene::load);
    QObject::connect(loadAction, &QAction::triggered,scene, validation);
    mainWidget.setWindowTitle("Dataflow tools: simplest calculator");
    mainWidget.resize(800, 600);
    mainWidget.showNormal();
    return app.exec();
}