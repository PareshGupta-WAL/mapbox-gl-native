#ifndef QQUICKMAPBOXSTYLEPROPERTY_H
#define QQUICKMAPBOXSTYLEPROPERTY_H

#include <QQuickItem>

class Q_DECL_EXPORT QQuickMapboxStyleProperty : public QQuickItem
{
    Q_OBJECT

    Q_ENUMS(Type)
    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString layer READ layer WRITE setLayer NOTIFY layerChanged)
    Q_PROPERTY(QString property READ property WRITE setProperty NOTIFY propertyChanged)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString styleClass READ styleClass WRITE setStyleClass NOTIFY classChanged)

public:
    enum Type {
        Unknown = 0,
        Layout,
        Paint
    };

    QQuickMapboxStyleProperty(QQuickItem *parent = 0);
    virtual ~QQuickMapboxStyleProperty();

    void setType(Type);
    Type type() const;

    void setLayer(const QString &);
    QString layer() const;

    void setProperty(const QString &);
    QString property() const;

    void setValue(const QVariant &);
    QVariant value() const;

    void setStyleClass(const QString &);
    QString styleClass() const;

signals:
    void typeChanged(Type);
    void layerChanged(const QString &);
    void propertyChanged(const QString &);
    void valueChanged(const QVariant &);
    void classChanged(const QString &);

    void layoutReady();
    void paintReady();

private:
    void checkReady();

    Type m_type = Unknown;
    QVariant m_layer;
    QVariant m_property;
    QVariant m_value;
    QVariant m_class;
};

#endif // QQUICKMAPBOXSTYLEPROPERTY_H
