#ifndef PREVIEWCONTROLLER_H_
#define PREVIEWCONTROLLER_H_

#include "gui/preview/PreviewModel.h"
#include "gui/preview/PreviewView.h"
#include "Controller.h"
#include "client/SaveInfo.h"
#include "client/ClientListener.h"

class LoginController;
class PreviewModel;
class PreviewView;
class PreviewController: public ClientListener {
	int saveId;
	int saveDate;
	PreviewModel * previewModel;
	PreviewView * previewView;
	LoginController * loginWindow;
	ControllerCallback * callback;
public:
	void NotifyAuthUserChanged(Client * sender) override;
	inline int SaveID() { return saveId; }

	bool HasExited;
	PreviewController(int saveID, bool instant, ControllerCallback * callback);
	PreviewController(int saveID, int saveDate, bool instant, ControllerCallback * callback);
	void Exit();
	void DoOpen();
	void OpenInBrowser();
	void Report(String message);
	void ShowLogin();
	bool GetDoOpen();
	SaveInfo * GetSaveInfo();
	PreviewView * GetView() { return previewView; }
	void Update();
	void FavouriteSave();
	bool SubmitComment(String comment);

	bool NextCommentPage();
	bool PrevCommentPage();

	virtual ~PreviewController();
};

#endif /* PREVIEWCONTROLLER_H_ */
