//#include "Task3.h" 	//Ó·˙ˇ‚ÎÂÌËÂ ÍÎ‡ÒÒÓ‚
//
///*----------------------------------------*/
///*        Ã≈“Œƒ€  À¿——¿ FigureBlank       */
///*----------------------------------------*/
//FigureBlank::FigureBlank(int InitX, int InitY, int initWidth, int initHeight) : VirtualFigure(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureBlank::~FigureBlank(void)
//{
//};
//
//void FigureBlank::Show(void) {
//	Visible = true;
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10);
//
//
//	// ÔˇÏÓÛ„ÓÎ¸ÌËÍ
//	SelectObject(hdc, BlackPen);
//
//	MoveToEx(hdc, X, Y, NULL);
//	Rectangle(hdc, X, Y, X + width, Y + height);
//}
//
//bool FigureBlank::IsHit(Stone* stone)
//{
//	int stoneX = stone->GetX(), stoneY = stone->GetY();
//	int stoneRadius = stone->GetRadius();
//	bool hitX = X + width >= stoneX - stoneRadius && X <= stoneX + stoneRadius;
//	bool hitY = Y + height >= stoneY - stoneRadius && Y <= stoneY + stoneRadius;
//
//	return hitX && hitY;
//}
//
//bool FigureBlank::IsHit(Suit* suit)
//{
//	int objectX = suit->GetX(), objectY = suit->GetY();
//	int left = objectX - (suit->GetD1() / 2), right = (suit->GetD1() / 2) + objectX;
//	int bottom = objectY + suit->GetD2();
//
//	bool hitX = X + width >= left && X <= right;
//	bool hitY = Y + height >= objectY && Y <= bottom;
//
//	return hitX && hitY;
//	return true;
//}
//
//bool FigureBlank::IsHit(Number* number)
//{
//	int objectX = number->GetX(), objectY = number->GetY();
//	int left = objectX, right = objectX + number->GetTenthWidth() * 2;
//	int bottom = objectY + number->GetTenthHeight() * 2;
//	bool hitX = X + width >= left && X <= right;
//	bool hitY = Y + height >= objectY && Y <= bottom;
//
//	return hitX && hitY;
//}
//
//bool FigureBlank::IsHit(FigureBlank* figure)
//{
//	int objectX = figure->GetX(), objectY = figure->GetY();
//	bool hitX = X + width >= objectX && X <= objectX + figure->GetWidth();
//	bool hitY = Y + height >= objectY && Y <= objectY + figure->GetHeight();
//
//	return hitX && hitY;
//}
//
//void FigureBlank::SetX(int newX) {
//	X = newX;
//}
//
//void FigureBlank::SetY(int newY) {
//	Y = newY;
//}
//
//int FigureBlank::GetWidth() {
//	return width;
//}
//
//int FigureBlank::GetHeight() {
//	return height;
//}
//
///*----------------------------------------*/
///*        Ã≈“Œƒ€  À¿——¿ FigureWithNumber  */
///*----------------------------------------*/
//FigureWithNumber::FigureWithNumber(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureWithNumber::~FigureWithNumber(void)
//{
//};
//
//void FigureWithNumber::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10);
//
//	// ˆËÙ‡ 7
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
//	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
//}
//
///*----------------------------------------*/
///*        Ã≈“Œƒ€  À¿——¿ FigureWithSuit    */
///*----------------------------------------*/
//FigureWithSuit::FigureWithSuit(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureWithSuit::~FigureWithSuit(void)
//{
//};
//
//void FigureWithSuit::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10);
//	// ÓÏ·
//
//	SelectObject(hdc, RedPen);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//}
//
///*----------------------------------------*/
///*        Ã≈“Œƒ€  À¿——¿ FigureWithHole    */
///*----------------------------------------*/
//FigureWithHole::FigureWithHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureWithHole::~FigureWithHole(void)
//{
//};
//
//void FigureWithHole::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50;
//
//	SelectObject(hdc, BlackPen);
//	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ FigureWithNumberAndSuit  */
///*----------------------------------------*/
//FigureWithNumberAndSuit::FigureWithNumberAndSuit(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureWithNumberAndSuit::~FigureWithNumberAndSuit(void)
//{
//};
//
//void FigureWithNumberAndSuit::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10);
//
//	// ˆËÙ‡ 7
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
//	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
//
//	// ÓÏ·
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ FigureWithNumberAndHole  */
///*----------------------------------------*/
//FigureWithNumberAndHole::FigureWithNumberAndHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureWithNumberAndHole::~FigureWithNumberAndHole(void)
//{
//};
//
//void FigureWithNumberAndHole::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50;
//
//	// ˆËÙ‡ 7
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
//	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
//
//	SelectObject(hdc, BlackPen);
//	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ FigureWithSuitAndHole    */
///*----------------------------------------*/
//FigureWithSuitAndHole::FigureWithSuitAndHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureWithSuitAndHole::~FigureWithSuitAndHole(void)
//{
//};
//
//void FigureWithSuitAndHole::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50;
//
//	// ÓÏ·
//
//	SelectObject(hdc, RedPen);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	SelectObject(hdc, BlackPen);
//	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ FigureComplete           */
///*----------------------------------------*/
//FigureComplete::FigureComplete(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//FigureComplete::~FigureComplete(void)
//{
//};
//
//void FigureComplete::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50;
//
//	// ˆËÙ‡ 7
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
//	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
//
//	// ÓÏ·
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//
//	SelectObject(hdc, BlackPen);
//	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ Figure rhomb8WithHole    */
///*----------------------------------------*/
//Figure rhomb8WithHole::Figure rhomb8WithHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//Figure rhomb8WithHole::~Figure rhomb8WithHole(void)
//{
//};
//
//void Figure rhomb8WithHole::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50,
//		numberRadius = 20;
//
//	// ˆËÙ‡ 7
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
//	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2 + numberRadius * 2, NULL);
//	Ellipse(hdc, shiftedX, shiftedY + numberRadius * 2, shiftedX + numberRadius * 2, shiftedY + numberRadius * 4);
//
//	// ÓÏ·
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//
//	SelectObject(hdc, BlackPen);
//	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ Figure rhomb7            */
///*----------------------------------------*/
//Figure rhomb7::Figure rhomb7(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//Figure rhomb7::~Figure rhomb7(void)
//{
//};
//
//void Figure rhomb7::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50;
//
//	// ˆËÙ‡ 7
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
//	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
//
//	// ÓÏ·
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ Figure rhomb8            */
///*----------------------------------------*/
//Figure rhomb8::Figure rhomb8(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//Figure rhomb8::~Figure rhomb8(void)
//{
//};
//
//void Figure rhomb8::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50,
//		numberRadius = 20;
//
//	// 8
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
//	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2 + numberRadius * 2, NULL);
//	Ellipse(hdc, shiftedX, shiftedY + numberRadius * 2, shiftedX + numberRadius * 2, shiftedY + numberRadius * 4);
//
//	// ÓÏ·
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ Figure rhomb10           */
///*----------------------------------------*/
//Figure rhomb10::Figure rhomb10(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//Figure rhomb10::~Figure rhomb10(void)
//{
//};
//
//void Figure rhomb10::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50,
//		numberRadius = 30;
//
//	// ˆËÙ‡ 10
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	LineTo(hdc, tenthWidth / 2 + X, Y + tenthHeight * 2);
//
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
//	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);
//
//	// ÓÏ·
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ Figure rhomb1           */
///*----------------------------------------*/
//Figure rhomb1::Figure rhomb1(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
//{
//}
//
//Figure rhomb1 ::~Figure rhomb1(void)
//{
//};
//
//void Figure rhomb1::Show(void) {
//	FigureBlank::Show();
//
//	int halfWidth = (width / 2),
//		fourthHeight = (height / 4),
//		fourthWidth = (width / 4),
//		tenthWidth = (width / 10),
//		tenthHeight = (height / 10),
//		radius = 50,
//		numberRadius = 30;
//
//	// ˆËÙ‡ 10
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
//	LineTo(hdc, tenthWidth / 2 + X, Y + tenthHeight * 2);
//
//	// ÓÏ·
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);
//
//	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
//	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
//}
//
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ Suit                     */
///*----------------------------------------*/
//Suit::Suit(int InitX, int InitY, int InitD1, int InitD2) : VirtualPoint(InitX, InitY)
//{
//	d1 = InitD1;
//	d2 = InitD2;
//}
//
//Suit::~Suit(void)
//{
//};
//
//void Suit::Show(void) {
//	Visible = true;
//	int halfWidth = d1 / 2,
//		halfHeight = d2 / 2;
//	// ÓÏ·
//
//	SelectObject(hdc, RedPen);
//
//	MoveToEx(hdc, X, Y, NULL);
//	LineTo(hdc, halfWidth + X, halfHeight + Y);
//
//	/*MoveToEx(hdc, halfWidth + X, Y + halfHeight, NULL);*/
//	LineTo(hdc, X, d2 + Y);
//
//	/*MoveToEx(hdc, X - halfWidth, Y + halfHeight, NULL);*/
//	LineTo(hdc, X - halfWidth, Y + halfHeight);
//
//	/*MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);*/
//	LineTo(hdc, X, Y);
//}
//
//void Suit::Hide(void) {
//	Visible = false;
//	int halfWidth = d1 / 2,
//		halfHeight = d2 / 2;
//	// ÓÏ·
//
//	SelectObject(hdc, WhitePen);
//
//	MoveToEx(hdc, X, Y, NULL);
//	LineTo(hdc, halfWidth + X, halfHeight + Y);
//
//	/*MoveToEx(hdc, halfWidth + X, Y + halfHeight, NULL);*/
//	LineTo(hdc, X, d2 + Y);
//
//	/*MoveToEx(hdc, X - halfWidth, Y + halfHeight, NULL);*/
//	LineTo(hdc, X - halfWidth, Y + halfHeight);
//
//	/*MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);*/
//	LineTo(hdc, X, Y);
//}
//
//int Suit::GetD1() {
//	return d1;
//}
//
//int Suit::GetD2() {
//	return d2;
//}
//
///*----------------------------------------*/
///* Ã≈“Œƒ€  À¿——¿ Number                   */
///*----------------------------------------*/
//Number::Number(int InitX, int InitY, int InitTenthWidth, int InitTenthHeight) : VirtualPoint(InitX, InitY)
//{
//	tenthWidth = InitTenthWidth;
//	tenthHeight = InitTenthHeight;
//}
//
//Number::~Number(void)
//{
//};
//
//void Number::Show(void) {
//	Visible = true;
//	// ˆËÙ‡ 7
//	SelectObject(hdc, RedPen);
//	MoveToEx(hdc, X, Y, NULL);
//	LineTo(hdc, tenthWidth * 2 + X, Y);
//	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
//}
//
//void Number::Hide(void) {
//	Visible = false;
//	// ˆËÙ‡ 7
//	SelectObject(hdc, WhitePen);
//	MoveToEx(hdc, X, Y, NULL);
//	LineTo(hdc, tenthWidth * 2 + X, Y);
//	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
//}
//
//int Number::GetTenthWidth() {
//	return tenthWidth;
//}
//
//int Number::GetTenthHeight() {
//	return tenthHeight;
//}