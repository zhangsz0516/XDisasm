#ifndef FORMDISASM_H
#define FORMDISASM_H

#include <QWidget>
#include <QScrollBar>
#include <QThread>
#include "xdisasmmodel.h"
#include "dialogdisasmlabels.h"

namespace Ui {
class XDisasmWidget;
}

class XDisasmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit XDisasmWidget(QWidget *parent = nullptr);
    void setData(QIODevice *pDevice,XDisasm::STATS *pStats,XDisasmModel::SHOWOPTIONS *pOptions);
    void goToAddress(qint64 nAddress);
    void clear();
    void waitTillModelLoaded(qint64 nAddress);
    ~XDisasmWidget();

private slots:
    void on_pushButtonLabels_clicked();
    void on_tableViewDisasm_customContextMenuRequested(const QPoint &pos);

private:
    Ui::XDisasmWidget *ui;
    XDisasmModel *pModel;
};

#endif // FORMDISASM_H
