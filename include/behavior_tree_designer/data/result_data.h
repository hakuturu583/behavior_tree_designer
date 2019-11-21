#ifndef BEHAVIOR_TREE_DESIGNER_RESULT_DATA_H_INCLUDED
#define BEHAVIOR_TREE_DESIGNER_RESULT_DATA_H_INCLUDED

// Headers in NodeEditor
#include <nodes/NodeDataModel>
#include <nodes/NodeData>

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::PortType;
using QtNodes::PortIndex;

class ResultData : public NodeData
{
    public:
        ResultData() {}
        NodeDataType type() const override
        {
            return NodeDataType {"resut", "ActionResult"};
        }
};

#endif //BEHAVIOR_TREE_DESIGNER_RESULT_DATA_H_INCLUDED