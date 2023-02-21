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
    ~CuCopySourceContextMenuActionPlugin();

    Q_INTERFACES(CuContextMenuActionsPlugin_I)

    // CuContextMenuActionsPlugin_I interface
public:
    void setup(QWidget *widget, const CuContextI *cuctx);
    QList<QAction *> getActions() const;
    int order() const;

protected slots:
    void onActionTriggered();

private:
    QList<QAction *>m_actions;
    const CuContextI *m_ctxi;

};






#endif // CUMBIACOPYSOURCECTXMENUACTION_H
