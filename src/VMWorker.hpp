#ifndef VMWORKER_H
#define VMWORKER_H

#include "QObject"
#include "QThread"
#include "VM.hpp"

class VMWorker : public QThread
{
    Q_OBJECT
public:
    VMWorker(VM* vm);

    static const int VM_NOT_LOADED = 0xFF;

public slots:
    void run();
    void pause();

signals:
    void quit();
    void error(int);
    void procReturn(int);
    void breakpoint();
    void stepDone();
    void runDone();
    void paused();
    void stopped();

private:
    VM* mVM;
    bool mPaused;
};

#endif // VMTHREAD_H
