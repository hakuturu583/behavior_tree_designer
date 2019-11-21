#include <behavior_tree_designer/nodes/root_node.h>

RootNodeDataModel::RootNodeDataModel() : _label(new QLabel("Root Node"))
{
    _label->setMargin(3);
}

unsigned int RootNodeDataModel::nPorts(PortType portType) const
{
    unsigned int result = 1;
    switch (portType)
    {
        case PortType::In:
            result = 0;
            break;
        case PortType::Out:
            result = 1;
        default:
            break;
    }
    return result;
}

NodeDataType RootNodeDataModel::dataType(PortType, PortIndex) const
{
    return ResultData().type();
}

std::shared_ptr<NodeData> RootNodeDataModel::outData(PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void RootNodeDataModel::setInData(std::shared_ptr<NodeData> data, int)
{
    auto root_node_data = std::dynamic_pointer_cast<ResultData>(data);
    _label->clear();
    _label->adjustSize();
}