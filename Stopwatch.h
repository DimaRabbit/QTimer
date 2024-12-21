#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    explicit Stopwatch(QObject* parent = nullptr);

    void start();
    void stop();
    void reset();
    QString getTime() const;
    QString getLapTime();

signals:
    void timeUpdated(const QString& time);

private slots:
    void update();

private:
    QTimer* timer;
    qint64 elapsedTime;
    qint64 lastLapTime;
};

#endif // STOPWATCH_H
