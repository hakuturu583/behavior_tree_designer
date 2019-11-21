#ifndef BEHAVIOR_TREE_DESIGNER_PRIORITY_DATA_H_INCLUDED
#define BEHAVIOR_TREE_DESIGNER_PRIORITY_DATA_H_INCLUDED

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

class PriorityData : public NodeData
{
    public:
        PriorityData() 
          : _priority(0)
        {}
        PriorityData(int const priority)
          : _priority(priority)
        {}
        NodeDataType type() const override
        {
            return NodeDataType {"priority", "Priority"};
        }
        int priority() const
        {
            return _priority;
        }
        QString priorityAsText() const
        {
            return QString::number(_priority); 
        }
    private:
        int _priority;
};

class PriorityDataModel : public NodeDataModel
{
    public:
        PriorityDataModel();
        virtual ~PriorityDataModel() {};
        QString caption() const override
        { 
            return QString("Priority Param");
        }
        bool captionVisible() const override
        {
            return true;
        }
        static QString Name()
        {
            return QString("Priority");
        }
        QString name() const override
        {
            return PriorityDataModel::Name();
        }
        unsigned int nPorts(PortType portType) const;
        NodeDataType dataType(PortType, PortIndex) const;
        std::shared_ptr<NodeData> outData(PortIndex);
        void setInData(std::shared_ptr<NodeData> data, int) override;
        QWidget * embeddedWidget() override { return _lineEdit; }
        QJsonObject save() const;
        void restore(QJsonObject const &p);
    private:
        QLineEdit * _lineEdit;
        std::shared_ptr<PriorityData> _priority;
    private Q_SLOTS:
        void onTextEdited(QString const &string);
};


#endif  //BEHAVIOR_TREE_DESIGNER_PRIORITY_DATA_H_INCLUDED