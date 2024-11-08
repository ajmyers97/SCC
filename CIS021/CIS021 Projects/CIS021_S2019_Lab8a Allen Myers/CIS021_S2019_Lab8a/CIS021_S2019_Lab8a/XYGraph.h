#pragma once
class XYGraph
{
public:
	XYGraph();
	~XYGraph();

	XYGraph(HWND);										// overloaded constructor

	void Draw(HDC);										// answer WM_PAINT message
	void LoadArray(double, double);						// load data into pArray
	void ShowLines();									// from main menu, turn draw the lines between data points

private:
	struct DPOINT										//struct to hold (x,y)
	{
		double x;
		double y;
	};

	HWND hWnd;											// local copy of handle to main window
	bool bShowLines;									// if true, show the lines between points

	int iPoints;										//index into pArray
	DPOINT pArray[POINTS_MAX];							//array holding input values
	DPOINT pPath[POINTS_MAX];							//shortest path along points
	int iPath[POINTS_MAX];								//order of data points


	void DrawPoints(HDC);								// draw the data points from the array
	void DrawLines(HDC);								// draw the lines between the points


	void CalcPath();									//calculate the shortest path along the array
	double GetDist(DPOINT,DPOINT);						//calculate distance between 2 points
};