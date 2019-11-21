#ifndef BEHAVIOR_TREE_DESIGNER_ACTION_DATA_H_INCLUDED
#define BEHAVIOR_TREE_DESIGNER_ACTION_DATA_H_INCLUDED

// Headers in NodeEditor
#include <nodes/NodeDataModel>
#include <nodes/NodeData>

// Headers in Qt
#include <QtWidgets/QLineEdit>
#include <QtGui/QDoubleValidator>

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::PortType;
using QtNodes::PortIndex;

class ActionData : public NodeData
{
    public:
        ActionData() 
          : _plugin_path("")
        {}
        ActionData(std::string const plugin_path)
          : _plugin_path(plugin_path)
        {}
        NodeDataType type() const override
        {
            return NodeDataType {"action", "ActionData"};
        }
        std::string plugin_path() const
        {
            return _plugin_path;
        }
        QString priorityAsText() const
        {
            return QString::fromUtf8(_plugin_path.c_str()); 
        }
    private:
        std::string _plugin_path;
};

class ActionDataModel : public NodeDataModel
{
    public:
        ActionDataModel();
        virtual ~ActionDataModel() {};
        QString caption() const override
        { 
            return QString("Action Plugin");
        }
        bool captionVisible() const override
        {
            return true;
        }
        static QString Name()
        {
            return QString("Action Plugin");
        }
        QString name() const override
        {
            return ActionDataModel::Name();
        }
        unsigned int nPorts(PortType portType) const;
        NodeDataType dataType(PortType, PortIndex) const;
        std::shared_ptr<NodeData> outData(PortIndex);
        void setInData(std::shared_ptr<NodeData> data, int) override;
        QWidget * embeddedWidget() override { return nullptr; }
};


#endif  //BEHAVIOR_TREE_DESIGNER_ACTION_DATA_H_INCLUDED