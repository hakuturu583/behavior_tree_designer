#include <behavior_tree_designer/data/priority_data.h>

PriorityDataModel::PriorityDataModel() : _lineEdit(new QLineEdit())
{
    _lineEdit->setValidator(new QDoubleValidator());
    _lineEdit->setMaximumSize(_lineEdit->sizeHint());
    connect(_lineEdit, &QLineEdit::textChanged,this, &PriorityDataModel::onTextEdited);
    _lineEdit->setText("1");
}

unsigned int PriorityDataModel::nPorts(PortType portType) const
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

QJsonObject PriorityDataModel::save() const
{
    QJsonObject modelJson = NodeDataModel::save();
    if (_priority)
    {
        modelJson["priority"] = QString::number(_priority->priority());
    }
    return modelJson;
}

void PriorityDataModel::restore(QJsonObject const &p)
{
    QJsonValue v = p["priority"];
    if (!v.isUndefined())
    {
        QString strNum = v.toString();

        bool ok;
        int priority_value = strNum.toInt(&ok);
        if (ok)
        {
            _priority = std::make_shared<PriorityData>(priority_value);
            _lineEdit->setText(strNum);
        }
    }
}

NodeDataType PriorityDataModel::dataType(PortType, PortIndex) const
{
    return PriorityData().type();
}

std::shared_ptr<NodeData> PriorityDataModel::outData(PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void PriorityDataModel::setInData(std::shared_ptr<NodeData> data, int)
{
    auto root_node_data = std::dynamic_pointer_cast<PriorityData>(data);
    _lineEdit->adjustSize();
}

void PriorityDataModel::onTextEdited(QString const &string)
{
    Q_UNUSED(string);
    bool ok = false;
    int priority = _lineEdit->text().toInt(&ok);
    if (ok)
    {
        _priority = std::make_shared<PriorityData>(priority);
        Q_EMIT dataUpdated(0);
    }
    else
    {
        Q_EMIT dataInvalidated(0);
    }
}