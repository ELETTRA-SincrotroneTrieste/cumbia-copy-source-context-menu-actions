#ifndef CUMBIACOPYSOURCECTXMENUACTION_H
#define CUMBIACOPYSOURCECTXMENUACTION_H

#include <cucontextmenuactionsplugin_i.h>
#include <QAction>
#include <QList>
#include <QObject>

class CuCopySourceContextMenuActionPlugin : public QObject, public CuContextMenuActionsPlugin_I
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" FILE "cumbia-copy-source-context-menu-actions.json")

public:
    explicit CuCopySourceContextMenuActionPlugin(QObject *parent = nullptr);

    Q_INTERFACES(CuContextMenuActionsPlugin_I)

    // CuContextMenuActionsPlugin_I interface
public:
    void setup(QWidget *widget, const CuContext *cuctx);
    QList<QAction *> getActions() const;
    int order() const;

protected slots:
    void onActionTriggered();

private:
    QList<QAction *>m_actions;
    const CuContext *m_ctx;

};






#endif // CUMBIACOPYSOURCECTXMENUACTION_H
