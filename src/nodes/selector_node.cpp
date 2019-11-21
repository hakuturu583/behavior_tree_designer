#include <behavior_tree_designer/nodes/selector_node.h>

SelectorNodeDataModel::SelectorNodeDataModel() : _lineEdit(new QLineEdit("1"))
{
    _lineEdit->adjustSize();
}

unsigned int SelectorNodeDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;
    switch (portType)
    {
        case PortType::In:
            result = 2;
            break;
        case PortType::Out:
            result = 1;
        default:
            break;
    }
    return result;
}

QWidget * SelectorNodeDataModel::embeddedWidget()
{
    return nullptr;
}

void SelectorNodeDataModel::onTextEdited(QString const &string)
{
    Q_UNUSED(string);
    bool ok = false;
    int priority = _lineEdit->text().toInt(&ok);
}

NodeDataType SelectorNodeDataModel::dataType(PortType portType, PortIndex portIndex) const
{
    switch (portType)
    {
        case PortType::In:
            switch (portIndex)
            {
                case 0:
                    return PriorityData().type();
                case 1:
                    return ResultData().type();
            }
            break;

        case PortType::Out:
            return ResultData().type();
        case PortType::None:
            break;
    }
    return NodeDataType();
}

std::shared_ptr<NodeData> SelectorNodeDataModel::outData(PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void SelectorNodeDataModel::setInData(std::shared_ptr<NodeData> data, int)
{
    auto result_data = std::dynamic_pointer_cast<ResultData>(data);
}