//
// Created by michiel on 17-8-2015.
//

#include "InitializationOperation.h"
#include "MouseOperations.h"
#include "SelectDomainOperation.h"

void InitializationOperation::Run(const Reciever &reciever)
{
    reciever.model->d = std::unique_ptr<PSTDFile>(PSTDFile::New("test.jps"));
    reciever.model->view->aspectMatrix = QMatrix4x4();
    reciever.model->view->viewMatrix = QMatrix4x4();
    reciever.model->view->worldMatrix = QMatrix4x4();
    reciever.model->view->Change();

    reciever.model->settings->visual.colorScheme = std::unique_ptr<StandardColorScheme>(new StandardColorScheme());
    reciever.model->settings->Change();

    //select none of the domains
    std::shared_ptr<SelectDomainOperation> op1(new SelectDomainOperation(-1));
    reciever.operationRunner->RunOperation(op1);

    //initialize Mouse handler
    std::shared_ptr<ChangeMouseHandlerOperations> op2(new ChangeMouseHandlerOperations(std::unique_ptr<MouseMoveSceneStrategy>(new MouseMoveSceneStrategy())));
    reciever.operationRunner->RunOperation(op2);
}