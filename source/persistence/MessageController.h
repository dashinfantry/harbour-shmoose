#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include <QSqlTableModel>

class Database;

class MessageController : public QSqlTableModel
{
	Q_OBJECT

public:
	explicit MessageController(QObject *parent = 0);
	MessageController(Database *db, QObject *parent = 0);

	Q_INVOKABLE QVariant data(const QModelIndex &requestedIndex, int role=Qt::DisplayRole ) const;
	virtual QHash<int, QByteArray> roleNames() const;

	void setFilterOnJid(QString const &jidFiler);
    void addMessage(const QString &id, QString const &jid, QString const &message, unsigned int direction);
    void markMessageReceived(QString const &id);

signals:
	void signalMessageReceived(unsigned int id, QString jid, QString message);

public slots:

private:
	void generateRoleNames();
	virtual void setTable ( const QString &table_name );
    int getRowNumberForId(QString const &id);

    void printSqlError();

	QHash<int, QByteArray> roles_;
	Database *database_;
};

#endif // MESSAGECONTROLLER_H