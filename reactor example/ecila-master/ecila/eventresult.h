#pragma once


#include "ecila.h"
#include "eventtype.h"








NS_ECILA_START

class IEventHandler;
class IAsyncResult;

class DECL_SPEC_DLL EventResult
:	public overlapped_t
{
public:

	 EventResult();
	~EventResult();

	void			Event		(EVENT_T e);
	int32_t 		Event		();

	void			Status		(bool_t v);
	bool_t			Status		();

	void			Error		(ulong_t v);
	ulong_t			Error		();

	void			Transffered	(ulong_t v);
	ulong_t			Transffered	();

	char_t*			Buffer		();
	void			Buffer		(char_t *buffer, int32_t size);
	int32_t			BufferSize	();

	wsabuf_t*		WSABuff		();

	void			Handler		(IEventHandler *h);
	IEventHandler*	Handler		();

	void			AcceptHandler(IEventHandler *h);
	IEventHandler*	AcceptHandler();

	void			ActImpl		(IAsyncResult *act_impl);
	IAsyncResult*	ActImpl		();

	void			Reset		(bool_t rst_act_impl_yn = FALSE);



private:

	EVENT_T			eventmask_;
	bool_t			status_;
	ulong_t			errno_;
	ulong_t			nbytes_;

	char_t			*buffer_;
	int32_t			buffer_size_;

	wsabuf_t		wsabuf_;
	
	IEventHandler	*handler_;
	IEventHandler	*accept_handler_;

	IAsyncResult	*act_impl_;
};

NS_ECILA_END

