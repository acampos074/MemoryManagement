#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // Commented this line to fix the segmentation fault
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    // TASK 4: Use move semantics
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
/*
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}
*/
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // TASK 5: Use move semantics
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // TASK 5: 
    //newNode->MoveChatbotHere(_chatBot);
    // Use move semantics
    newNode->MoveChatbotHere(std::move(_chatBot));
    // Comment this line
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //return _childEdges[index];
    // TASK 4: using the member function .get()
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}