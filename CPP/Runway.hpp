#include <queue>
using namespace std;
enum Runway_activity {idle, land, takeoff};
class Runway {
public:
	Runway(int limit);
	bool can_land(const Plane &current);
	bool can_depart(const Plane &current);
	Runway_activity activity(int time);
	void shut_down(int time) const;
private:
	queue<Plane> landing;
	queue<Plane> takeoff;
	int queue_limit;
	int num_land_requests;
	int num_takeoff_requests;
	int num_landings;
	int num_takeoffs;
	int num_land_accepted;
	int num_takeoff_accepted;
	int num_land_refused;
	int num_takeoff_refused;
	/**
	 * total time of planes waiting to land.
	 */
	int land_wait;
	/**
	 * total time of planes waiting to take off.
	 */
	int takeoff_wait;
	/**
	 * total time of runway is idle.
	 */
	int idle_time;
};
