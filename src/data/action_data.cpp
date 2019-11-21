#include <behavior_tree_designer/data/action_data.h>

ActionDataModel::ActionDataModel()
{
}

unsigned int ActionDataModel::nPorts(PortType portType) const
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

NodeDataType ActionDataModel::dataType(PortType, PortIndex) const
{
    return ActionData().type();
}

std::shared_ptr<NodeData> ActionDataModel::outData(PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void ActionDataModel::setInData(std::shared_ptr<NodeData> data, int)
{
    auto action_data = std::dynamic_pointer_cast<ActionData>(data);
}