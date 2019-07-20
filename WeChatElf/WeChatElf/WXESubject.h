#pragma once

#include "WXESubjectImpl.h"

class WXESubject;

using WXEUserSubjectMap = std::map<DWORD, WXESubject>;

enum WXEError
{

};

class WXESubject {
public:
	WXESubject(const WXESubject& val);
	~WXESubject();
	static WXESubject& createSubject(DWORD address);

public:
	/*
	*	��½����
	*/
	std::wstring& getLoginQRCode() const;
	std::wstring& getLoginInfo() const;
	std::wstring& getLogoutInfo() const;

	/*
	*	��ȡ�û���Ϣ
	*/
	void getInfoOfOwner() const;
	void getInfoOfFriends(std::vector<int>& friends) const;
	void getInfoOfRoom(std::vector<int>& room) const;
	void getInfoOfRoomMember(std::vector<int>& members) const;
	void getInfoOfOfficialAccount(std::vector<int>& accounts) const;
	void getInfoOfOwnerFromNetwork() const;
	void getInfoOfRoomMemberFromNetwork(std::vector<int>& members) const;

	/*
	*	���Ѳ���
	*/
	void addFriends(std::vector<int>& friends) const;
	void deleteFriends(std::vector<int>& friends) const;
	void setStarMarkToFriends(std::vector<int>& friends) const;
	void cancelStarMarkToFriends(std::vector<int>& friends) const;
	void modifyFriendNotes(std::vector<int>& friends) const;
	void agreeFriendRequest(std::wstring& friends) const;
	void receiveFriendTransfer() const;
	void agreeRoomInvitaionOfFriend() const;

	/*
	*	Ⱥ����
	*/
	void createChatRoom() const;
	void deleteAndQuitChatRoom() const;
	void inviteFriendToJoinRoom() const;  //ֱ������Ⱥ
	void inviteFriendToJoinRoomEx() const; //��Ҫ����ͬ��
	void kickRoomMember() const;
	void modifyRoomName()const;
	void setRoomAnnouncement() const;
	void modifyMyRoomNickName() const;
	void saveRoomToAddressBook() const;
	void removeRoomToAddressBook() const;

	/*
	*	������Ϣ
	*/
	void sendTextMessage() const;
	void sendAtRoomMemberMessage() const;
	void sendNameCardMessage() const;
	void sendLinkMessage() const;
	void sendPictureMessage() const;
	void sendFileMessage() const;
	void sendVideoMessage() const;
	void sendGifMessage()const;

	/*
	*	������Ϣ
	*/
	void openReceiveMessage() const;
	void stopReceiveMessage() const;
	void preventWithdrawalMessage() const;
	
	/*
	*	�ļ�����
	*/
	void decodePictureMetadata() const;
	void forwardFileMessage() const;

	/*
	*	�Զ�����
	*/
	void autoDownloadFile() const;
	void autoReceiveTransfer() const;
	void autoAgreeRoomInvitaion() const;
	void autoAgreeFriendInvitation() const;
	void autoAddSharedNameCard() const;

	/*
	*	���ݿ����
	*/
	void query() const;

private:
	WXESubject(DWORD address);

private:
	/*
	*  ΢��ģ���ַ
	*/
	DWORD winBaseAddress;

private:
	/*
	*  �������ʵ�ֶ���
	*/
	std::unique_ptr<WXESubjectImpl> implementation;

private:
	/*
	* �û���Subject�Ķ�Ӧ��ϵ��ͨ��User��DWORD�����ҵ���Ӧ��΢�Ž���
	*/
	static DWORD userNumber;
	static WXEUserSubjectMap userMap;
	static std::mutex mutexLock;
};

