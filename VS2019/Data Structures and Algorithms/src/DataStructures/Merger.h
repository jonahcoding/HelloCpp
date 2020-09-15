#pragma once

//Provide operation interface.
template<class T>
class Merger
{
public:
	virtual T merger(T a, T b) = 0;
};
