#include <iostream>
#include <cmath>
#include <map>
using namespace std;
class Point
{
	private:
		int x;
		int y;
	public:
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		Point(int x,int y);
		int manhattonDistance(Point to);
};
class Distribution;
class Logistics;
class Store;
class Building
{
	public:
		int id;
		Point& position;
		int cost;
		int revenue;
		int expense;
		map<int,Distribution*> distribution;
		int costPerKM;
	protected:
		Building();
		Building(int id, Point position,int cost);
		Building(const Building& b);
		Building& operator=(const Building& b);
		virtual ~Building();
	public:
		int getCost()
		{
			return cost;
		}
		int getRevenue()
		{
			return revenue;
		}
		int getExpense()
		{
			return expense;
		}
		int manhattonDistance(Building to);
		int getNet();
		int compareNet(Building b1, Building b2);
		double getOperatingExpenseRatio();
		int copareOER(Building b1, Building b2);
		int send(Logistics from, Store to, int units);
};

/**Zhen start*/ 
class Logistics: public Building //subclass
{
	private:
		const int capacity;
		map <int, Store*> possibleStores;
		int unsold;
	public:
		// Constructors
		Logistics(int id, Point position, int cost, int capacity);
		Logistics(const Logistics& l);
		Logistics& operator=(const Logistics& l);
<<<<<<< HEAD
		~Logistics();
		// Functions
=======
		int getLogisticsCapacity()
		{
			return capacity;
		}
		int getLogisticsUnsold()
		{
			return unsold;
		}
		map <int, Store*> getPossibleStores();
>>>>>>> refs/remotes/origin/master
		int send(Store to, int units);
		void include(Store s);
		void include(Store* ss, int sNum);
		//Getters
		int getCapacity();
		map <int, Store*>& getPossibleStores;
		int getUnsold();
};

class Store:public Building//subclass
{
	private:
		const int demand;
		map <int, Logistics*> possibleLogistics;
		const int price;
		int unsatisfied;
	public:
		// Constructors
		Store(int id, Point position, int cost, int demand, int price);
		Store(const Store& s);
<<<<<<< HEAD
		~Store();
		// Functions
=======
		Store& operator=(const Store& s);
		int getDemand()
		{
			return demand;
		}
		map <int, Logistics*> getPossibleLogistics();
		int getPrice()
		{
			return price;
		}
		int getUnsatisfied()
		{
			return unsatisfied;
		}
>>>>>>> refs/remotes/origin/master
		int receive(Logistics from, int units);
		void include(Logistics l);
		void include(Logistics* ls, int lNum);
		// Getters
		int getDemand();
		map <int, Logistics*>& getPossibleLogistics;
		int getPrice();
		int getUnsatisfied();		
};

class Distribution
{
	private:
<<<<<<< HEAD
		const Logistics& from;
		const Store& to;
		const int price;
		const int unitCost;
		const int units;
	public:
		// Constructors
		Distribution(Logistics from, Store to);
		~Distribution();
		// Functios
		int getUnitNet();
		int getNet();
		// Getters
		Logistics getFrom();
		Store getTo();		
		int getPrice();
		int getUnitCost();
		int getUnits();
=======
		Logistics& from;
		Store& to;
	public:
		const int price;
		const int unitCost;
		const int units;

		Distribution(Logistics from, Store to);
		Logistics& getFrom();
		Store& getTo();
		int getUnitNet()
		{
			return price-unitCost;
		}
		int getNet()
		{
			return units*(price-unitCost);
		}
		int getPrice()
		{
			return price;
		}
		int getUnitCost()
		{
			return unitCost;
		}
		int getUnits()
		{
			return units;
		}

>>>>>>> refs/remotes/origin/master
};
/** Zhen end */


/** JasonBaby start */
class Plan
{
private:
    map<int,Logistics*> logistics;
    map<int,Store*> stores;
    int revenue;
    int expense;
    map<int,Logistics*> unsold;
    map<int,Store*> unsatisfied;
public:
	// Static fields
	static int numLogistics;
	static int numStores;
	// Constructors
	Plan(const Logistics* ls, int lNum, const Store* ss, int sNum);
	Plan(const Plan& p);
	Plan& operator=(const Plan& p);
	// Functions
	int getNet() const;
	string toString() const;
	bool remove(Building* building);
	void update();
	// Accessors
    map<int,Logistics*>& getLogistics();
    map<int,Store*>& getStores();
    int getRevenue();
    int getExpense();
    map<int,Logistics*>& getUnsold();
    map<int,Store*>& getUnsatisfied();
};
/** JasonBaby end */

int main()
{

	return 0;
}

/** JasonBaby start */
// For Plan


/** JasonBaby end */
int Point:: manhattonDistance(Point to)
{
	int manhattonDistance = 0;
	manhattonDistance = abs(x - to.x) + abs(y - to.y);
	return manhattonDistance;
}

/** Zhen start */
// Logistics
// Constructors   
Logistics::	Logistics(int id, Point position, int cost, int capacity)
{
	this->id = id;
	this->position = position;
	this->cost = cost;
	this->capacity = capacity;		
}
Logistics:: Logistics(const Logistics& l);// copy constructor
Logistics::	Logistics& operator=(const Logistics& l);
Logistics::	~Logistics();
// Functions
int Logistics::send(Store to, int units)
{
	int send = Building::send(*this, to, units);
	return send;
}
void Logistics::include(Store s)
{
	if(s.getDemand()!=0)
	{
		if(s.costPerKM*s.position.manhattonDistance(*this.position)<s.price)
		{
			possibleStores[s.id]=s;//???
		}
	}
}
void Logistics::include(Store* ss, int sNum)
{
	
}
//Getters
Logistics::	int getCapacity()
{
	return capacity;
} 
Logistics::	int getUnsold()
{
	return unsold;
}

// Store 



int getDemand()
		{
			return demand;
		}
		int getPrice()
		{
			return price;
		}
		int getUnsatisfied()
		{
			return unsatisfied;
		}		

// Distribution
int getUnitNet()
		{
			return price-unitCost;
		}
		int getNet()
		{
			return units*(price-unitCost);
		}





Distribution :: Distribution()
{
	this-> from = nullptr;
	this-> to = nullptr;
}
Distribution :: Distribution(Logistics from, Store to)
{
	this-> from = from;
	this-> to = to;
}


int getPrice()
		{
			return price;
		}
		int getUnitCost()
		{
			return unitCost;
		}
		int getUnits()
		{
			return units;
		}





/** Zhen end */




