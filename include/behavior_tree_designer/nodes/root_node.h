#ifndef BEHAVIOR_TREE_DESIGNER_ROOT_NODE_H_INCLUDED
#define BEHAVIOR_TREE_DESIGNER_ROOT_NODE_H_INCLUDED

// Headers in NodeEditor
#include <nodes/NodeDataModel>
#include <nodes/NodeData>

// Headers in Qt
#include <QtWidgets/QLabel>

// Headers in this package
#include <behavior_tree_designer/data/result_data.h>

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::PortType;
using QtNodes::PortIndex;

class RootNodeDataModel : public NodeDataModel
{
    public:
        RootNodeDataModel();
        virtual ~RootNodeDataModel() {};
        QString caption() const override
        { 
            return QString("Root Node");
        }
        bool captionVisible() const override
        {
            return true;
        }
        static QString Name()
        {
            return QString("RootNode");
        }
        QString name() const override
        {
            return RootNodeDataModel::Name();
        }
        unsigned int nPorts(PortType portType) const;
        NodeDataType dataType(PortType, PortIndex) const;
        std::shared_ptr<NodeData> outData(PortIndex);
        void setInData(std::shared_ptr<NodeData> data, int) override;
        QWidget * embeddedWidget() override { return nullptr; }
    private:
        QLabel * _label;
};

#endif  //BEHAVIOR_TREE_DESIGNER_ROOT_NODE_H_INCLUDED