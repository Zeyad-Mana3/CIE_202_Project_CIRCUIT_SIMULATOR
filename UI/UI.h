#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point
{
	int x,y;
};


//A structure to contain drawing parameters for each component/connection
//Each component stores its drawing points in this struct 
//For example, a resistor can store points of the rectangluar area it occupies
//The Connection can store the points of its line segments
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}

};


class UI
{

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{

		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_RES,		//ADD NEW RES ITEM TO MENU
		ITM_BATTERY, // ADDING NEW BATTERY ITEM IN MENU
		ITM_BULB,	//ADDING NEW BULB ITEM TO MENU
		ITM_FUSE,	//ADDING NEW FUSE ITEM TO MENU
		ITM_SWITCH,		//ADDING NEW SWITCH ITEM TO MENU
		ITM_BUZZER,		//ADDING NEW BUZZER ITEM TO MENU
		ITM_GROUND,		//ADDING NEW GROUND ITEM TO MENU
		ITM_CONNECTION, // Adding connection line
		ITM_MODULE,
		ITM_EDIT,		// eidt
		ITM_DEL,		//DELETE
		ITM_EXIT,		//Exit item
		
		ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	};


	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_CIRC_SIM,	//Circuit Simulate menu item
		ITM_CIRC_DESIGN,
		ITM_AMETER,
		ITM_VOLTMETER,

			//CICUIT DESIGN MENU  ITEM
		//TODO:Add more items names here
	
		ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
	};


	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1200, height = 650,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 80,		//Width of each item in toolbar menu

						//Arbitrary values, you can change as you wish
						COMP_WIDTH = 50,		//Component Image width
						COMP_HEIGHT = 50;		//Component Image height

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	window *pWind;
	
public:
	
	UI();
	int getCompWidth() const;	//returns Component width
	int getCompHeight() const;	//returns Component height
	void setAppMode(MODE x);
	
	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y);
	//Get coordinate where user clicks
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	
	// Output Functions  ---------------------------
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

		
	// Draws a resistor
	void DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	// Draws a battery
	void Drawbattery(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws a Switch
	void DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws a Bulb
	void DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws a Switch
	void DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws a Fuse
	void DrawFuse(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws a Bulb
	void DrawGround(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawModule(const GraphicsInfo& r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other components, connections, .. etc

	// Draws Connection
	void DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar

	void DeleteComp(const GraphicsInfo& r_GfxInfo) const;

	void DeleteConn(const GraphicsInfo& r_GfxInfo);


	~UI();
};