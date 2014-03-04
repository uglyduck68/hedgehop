// $Id: HAStatus.cpp 91626 2010-09-07 10:59:20Z johnnyw $

#include "ClientAcceptor.h"

// Listing 12 code/ch07
class LoopStopper : public ACE_Event_Handler
{
public:
  LoopStopper (int signum = SIGINT);

  // Called when object is signaled by OS.
  virtual int handle_signal (int signum,
                             siginfo_t * = 0,
                             ucontext_t * = 0);
};

LoopStopper::LoopStopper (int signum)
{
  ACE_Reactor::instance ()->register_handler (signum, this);
}

int
LoopStopper::handle_signal (int, siginfo_t *, ucontext_t *)
{
  ACE_Reactor::instance ()->end_reactor_event_loop ();
  return 0;
}
// Listing 12

// Listing 13 code/ch07
#include "ace/Signal.h"

class LogSwitcher : public ACE_Event_Handler
{
public:
  LogSwitcher (int on_sig, int off_sig);

  // Called when object is signaled by OS.
  virtual int handle_signal (int signum,
                             siginfo_t * = 0,
                             ucontext_t * = 0);

  // Called when an exceptional event occurs.
  virtual int handle_exception (ACE_HANDLE fd = ACE_INVALID_HANDLE);

private:
  LogSwitcher () {}

  int on_sig_;       // Signal to turn logging on
  int off_sig_;      // Signal to turn logging off
  int on_off_;       // 1 == turn on, 0 == turn off
};

LogSwitcher::LogSwitcher (int on_sig, int off_sig)
  : on_sig_ (on_sig), off_sig_ (off_sig)
{
  ACE_Sig_Set sigs;
  sigs.sig_add (on_sig);
  sigs.sig_add (off_sig);
  ACE_Reactor::instance ()->register_handler (sigs, this);
}
// Listing 13

// Listing 14 code/ch07
int
LogSwitcher::handle_signal (int signum, siginfo_t *, ucontext_t *)
{
  if (signum == this->on_sig_ || signum == this->off_sig_)
    {
      this->on_off_ = signum == this->on_sig_;
      ACE_Reactor::instance ()->notify (this);
    }
  return 0;
}
// Listing 14

// Listing 15 code/ch07
int
LogSwitcher::handle_exception (ACE_HANDLE)
{
  if (this->on_off_)
    ACE_LOG_MSG->clr_flags (ACE_Log_Msg::SILENT);
  else
    ACE_LOG_MSG->set_flags (ACE_Log_Msg::SILENT);
  return 0;
}
// Listing 15

// Listing 11 code/ch07
int ACE_TMAIN (int, ACE_TCHAR *[])
{
  ACE_INET_Addr port_to_listen ("HAStatus");
  ClientAcceptor acceptor;
  acceptor.reactor (ACE_Reactor::instance ());
  if (acceptor.open (port_to_listen) == -1)
    return 1;

  ACE_Reactor::instance ()->run_reactor_event_loop ();

  return (0);
}
// Listing 11
