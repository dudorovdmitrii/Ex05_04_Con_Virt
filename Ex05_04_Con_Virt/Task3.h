//#include "Task2.h";
//
//class Suit : public VirtualPoint {
//protected:
//	int d1;
//	int d2;
//public:
//	Suit(int InitX, int InitY, int d1, int d2);
//	~Suit(); //äåñòğóêòîğ
//
//	int GetD1();
//	int GetD2();
//	void Show(void);
//	void Hide(void);
//};
//
//class Number : public VirtualPoint {
//protected:
//	int tenthWidth;
//	int tenthHeight;
//public:
//	Number(int InitX, int InitY, int tenthWidth, int tenthHeight);
//	~Number(); //äåñòğóêòîğ
//
//	int GetTenthWidth();
//	int GetTenthHeight();
//	void Show(void);
//	void Hide(void);
//};
//
//class FigureBlank : public VirtualFigure
//{
//public:
//	FigureBlank(int InitX, int InitY, int width, int height);
//	~FigureBlank(); //äåñòğóêòîğ
//
//	void Show(void);
//	bool IsHit(Stone* stone);
//	bool IsHit(Suit* suit);
//	bool IsHit(Number* number);
//	bool IsHit(FigureBlank* figure);
//
//	void SetX(int newX);
//	void SetY(int newY);
//
//	int GetHeight();
//	int GetWidth();
//};
//
//class FigureWithNumber : public FigureBlank
//{
//public:
//	FigureWithNumber(int InitX, int InitY, int width, int height);
//	~FigureWithNumber(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureWithSuit : public FigureBlank
//{
//public:
//	FigureWithSuit(int InitX, int InitY, int width, int height);
//	~FigureWithSuit(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureWithHole : public FigureBlank
//{
//public:
//	FigureWithHole(int InitX, int InitY, int width, int height);
//	~FigureWithHole(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureWithNumberAndSuit : public FigureBlank
//{
//public:
//	FigureWithNumberAndSuit(int InitX, int InitY, int width, int height);
//	~FigureWithNumberAndSuit(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureWithNumberAndHole : public FigureBlank
//{
//public:
//	FigureWithNumberAndHole(int InitX, int InitY, int width, int height);
//	~FigureWithNumberAndHole(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureWithSuitAndHole : public FigureBlank
//{
//public:
//	FigureWithSuitAndHole(int InitX, int InitY, int width, int height);
//	~FigureWithSuitAndHole(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureComplete : public FigureBlank
//{
//public:
//	FigureComplete(int InitX, int InitY, int width, int height);
//	~FigureComplete(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureÊrhomb1 : public FigureBlank
//{
//public:
//	FigureÊrhomb1(int InitX, int InitY, int width, int height);
//	~FigureÊrhomb1(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureÊrhomb7 : public FigureBlank
//{
//public:
//	FigureÊrhomb7(int InitX, int InitY, int width, int height);
//	~FigureÊrhomb7(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureÊrhomb10 : public FigureBlank
//{
//public:
//	FigureÊrhomb10(int InitX, int InitY, int width, int height);
//	~FigureÊrhomb10(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureÊrhomb8 : public FigureBlank
//{
//public:
//	FigureÊrhomb8(int InitX, int InitY, int width, int height);
//	~FigureÊrhomb8(); //äåñòğóêòîğ
//
//	void Show(void);
//};
//
//class FigureÊrhomb8WithHole : public FigureBlank
//{
//public:
//	FigureÊrhomb8WithHole(int InitX, int InitY, int width, int height);
//	~FigureÊrhomb8WithHole(); //äåñòğóêòîğ
//
//	void Show(void);
//};