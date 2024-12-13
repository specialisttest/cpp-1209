#ifndef __READONLY_STORAGE_H__
#define __READONLY_STORAGE_H__

template<class T>
class ReadonlyStorage
{
	protected:
		T _data;
		
	public:
		ReadonlyStorage(T data) : _data(data) {}
		
		ReadonlyStorage(const ReadonlyStorage&) = delete;
		ReadonlyStorage& operator=(const ReadonlyStorage&) = delete;
		
		ReadonlyStorage<T> operator+(const ReadonlyStorage<T>& p) {
			return ReadonlyStorage<T>(this->getData()+ p.getData());
		}
		
		T getData() const;
};

template<class T>
T ReadonlyStorage<T>::getData() const
{
	return _data;
}

typedef ReadonlyStorage<double> RSD;
class MS : public RSD //ReadonlyStorage<double>
{
	
};

template<class T>
class ModifiableStorage : public ReadonlyStorage<T>
{
	public:
		ModifiableStorage(T data) : ReadonlyStorage<T>(data)
		{}
		
		void setData(T data) { 
			this->ReadonlyStorage<T>::_data = data; 
		}
};




#endif
