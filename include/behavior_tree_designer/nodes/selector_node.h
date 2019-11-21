#ifndef BEHAVIOR_TREE_DESIGNER_SELECTOR_NODE_H_INCLUDED
#define BEHAVIOR_TREE_DESIGNER_SELECTOR_NODE_H_INCLUDED

// Headers in NodeEditor
#include <nodes/NodeDataModel>
#include <nodes/NodeData>

// Headers in Qt
#include <QtWidgets/QLineEdit>
#include <QHBoxLayout>

// Headers in this package
#include <behavior_tree_designer/data/result_data.h>
#include <behavior_tree_designer/data/priority_data.h>

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::PortType;
using QtNodes::PortIndex;

class SelectorNodeDataModel : public NodeDataModel
{
    public:
        SelectorNodeDataModel();
        virtual ~SelectorNodeDataModel() {};
        QString caption() const override
        { 
            return QString("Selector Node");
        }
        bool captionVisible() const override
        {
            return true;
        }
        static QString Name()
        {
            return QString("SelectorNode");
        }
        QString name() const override
        {
            return SelectorNodeDataModel::Name();
        }
        unsigned int nPorts(PortType portType) const;
        NodeDataType dataType(PortType portType, PortIndex portIndex) const;
        std::shared_ptr<NodeData> outData(PortIndex);
        void setInData(std::shared_ptr<NodeData> data, int) override;
        QWidget * embeddedWidget() override;
    private:
        QLineEdit * _lineEdit;
    private Q_SLOTS:
        void onTextEdited(QString const &string);
};

#endif  //BEHAVIOR_TREE_DESIGNER_SELECTOR_NODE_H_INCLUDED