#include <QQuickMapboxStyleProperty>

QQuickMapboxStyleProperty::QQuickMapboxStyleProperty(QQuickItem *parent_)
    : QQuickItem(parent_)
{
}

QQuickMapboxStyleProperty::~QQuickMapboxStyleProperty()
{
}

void QQuickMapboxStyleProperty::checkReady()
{
    if (m_type == Unknown || m_layer.isNull() || m_property.isNull() || m_value.isNull()) {
        return;
    }

    if (m_type == Layout) {
        emit layoutReady();
    } else {
        emit paintReady();
    }
}

void QQuickMapboxStyleProperty::setType(Type type)
{
    if (type == m_type) {
        return;
    }

    m_type = type;
    emit typeChanged(type);
    checkReady();
}

QQuickMapboxStyleProperty::Type QQuickMapboxStyleProperty::type() const
{
    return m_type;
}

void QQuickMapboxStyleProperty::setLayer(const QString &layer)
{
    if (layer == m_layer.toString()) {
        return;
    }

    m_layer = layer;
    emit layerChanged(layer);
    checkReady();
}

QString QQuickMapboxStyleProperty::layer() const
{
    return m_layer.toString();
}

void QQuickMapboxStyleProperty::setProperty(const QString &property)
{
    if (property == m_property.toString()) {
        return;
    }

    m_property = property;
    emit propertyChanged(property);
    checkReady();
}

QString QQuickMapboxStyleProperty::property() const
{
    return m_property.toString();
}

void QQuickMapboxStyleProperty::setValue(const QVariant &value)
{
    if (value == m_value) {
        return;
    }

    m_value = value;
    emit valueChanged(value);
    checkReady();
}

QVariant QQuickMapboxStyleProperty::value() const
{
    return m_value;
}

void QQuickMapboxStyleProperty::setStyleClass(const QString &styleClass)
{
    if (styleClass == m_class.toString()) {
        return;
    }

    m_class = styleClass;
    emit classChanged(styleClass);
    checkReady();
}

QString QQuickMapboxStyleProperty::styleClass() const
{
    return m_class.toString();
}
