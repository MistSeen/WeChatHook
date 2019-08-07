#pragma once

#include "WXECommon.h"

class WXESubjectImpl;

class WXESubject {
public:
	WXESubject(WXEVersion version, DWORD address);
	~WXESubject();

public:
	/*
	*	��½����
	*/
	void getLoginQRCode() const;
	void getLoginInfo() const;
	void getLogoutInfo() const;

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
	void sendFriendVerification(const std::wstring& wxid, const std::wstring& verifyText) const;
	void deleteFriends(std::vector<int>& friends) const;
	void setStarMarkToFriends(std::vector<int>& friends) const;
	void cancelStarMarkToFriends(std::vector<int>& friends) const;
	void modifyFriendNotes(std::vector<int>& friends) const;
	void agreeFriendRequest(const std::wstring& v1Str, const std::wstring& v2Str) const;
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
	void modifyRoomName() const;
	void setRoomAnnouncement() const;
	void modifyMyRoomNickName() const;
	void saveRoomToAddressBook() const;
	void removeRoomToAddressBook() const;
	void addFriendsFromRoom() const;

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
	void sendGifMessage() const;
	void switchReceiveMessage(bool isOpen) const;
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
	/*
	*  �������ʵ�ֶ���
	*/
	std::shared_ptr<WXESubjectImpl> pImpl;
};

