#include "StudentsModel.h"

StudentsModel::~StudentsModel()
{
}

int StudentsModel::rowCount(const QModelIndex & parent) const
{
	return this->moviesArr.size();
}

int StudentsModel::columnCount(const QModelIndex & parent) const
{
	return 6;
}

QVariant StudentsModel::data(const QModelIndex & index, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	int row = index.row();
	int column = index.column();
	Movie m = this->moviesArr[row];

	switch (column)
	{
	case 0:
		return QString::fromStdString(m.getTitle());
	case 1:
		return QString::fromStdString(m.getGenre());
	case 2:
		return QString::number(m.getYear());
	case 3:
		return QString::number(m.getLikes());
	case 4:
		return QString::fromStdString(m.getTrailer());
	case 5:
		return QString::number(m.getMinutes());
	}

	return QVariant();
}

QVariant StudentsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();
	if (orientation == Qt::Horizontal) {
		switch (section)
		{
		case 0:
			return QString("Title");
		case 1:
			return QString("Genre");
		case 2:
			return QString("Year");
		case 3:
			return QString("Likes");
		case 4:
			return QString("Trailer");
		case 5:
			return QString("Minutes");
		}
	}
	return QVariant();
}

Qt::ItemFlags StudentsModel::flags(const QModelIndex & index) const
{
	if (index.column() > 1)
	{
		return Qt::ItemIsEditable | Qt::ItemIsSelectable| Qt::ItemIsEnabled;
	}
	return Qt::ItemFlags();
}

/*bool StudentsModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (role != Qt::EditRole)
		return false;
	if (index.column() < 2)
		return false;
	Movie m = this->moviesArr[index.row()];

	if (index.column() == 2)
		s.setLabGrade(value.toDouble());
	if (index.column() == 3)
		s.setSeminarGrade(value.toDouble());
	emit dataChanged(index,index);
	return true;
}*/
