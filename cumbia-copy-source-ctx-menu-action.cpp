#include "cumbia-copy-source-ctx-menu-action.h"
#include <QClipboard>
#include <cucontrolsreader_abs.h>
#include <cucontrolswriter_abs.h>
#include <QApplication>
#include <cucontext.h>
#include <cucontexti.h>

CuCopySourceContextMenuActionPlugin::CuCopySourceContextMenuActionPlugin(QObject *parent) : QObject(parent)
{
    m_ctxi = nullptr;
}

CuCopySourceContextMenuActionPlugin::~CuCopySourceContextMenuActionPlugin()
{
    m_actions.clear();
}

void CuCopySourceContextMenuActionPlugin::setup(QWidget *widget, const CuContextI *cuctx)
{
    Q_UNUSED(widget);
    m_ctxi = cuctx;
    if(m_actions.isEmpty()) {
        QAction *a  = new QAction("Copy source", this);
        connect(a, SIGNAL(triggered()), this, SLOT(onActionTriggered()));
        m_actions << a;
    }
}

QList<QAction *> CuCopySourceContextMenuActionPlugin::getActions() const
{
    return m_actions;
}

int CuCopySourceContextMenuActionPlugin::order() const
{
    return 10;
}

void CuCopySourceContextMenuActionPlugin::onActionTriggered()
{
    QClipboard *clipb = qApp->clipboard();
    CuControlsWriterA *w = nullptr;
    CuControlsReaderA* r = m_ctxi->getReader();
    if(r)
        clipb->setText(r->source());
    else if((w = m_ctxi->getWriter()) != nullptr)
        clipb->setText(w->target());

    if(!r && !w)
        perr("CuCopySourceContextMenuActionPlugin.onActionTriggered: neither a reader nor a writer are configured");
}
