#pragma once
#ifdef _MANAGED

struct AutoDetectDelegateType {};

template<typename TDelegate, typename TLambda, typename TRet, typename ...TParams>
ref class LambdaHolder;

template<typename TDelegate, typename TLambda, typename TRet, typename ...TParams>
ref class LambdaHolder
{
public:
	inline LambdaHolder(const TLambda % func) { m_func = new TLambda(func); }
	!LambdaHolder() { delete m_func; }
	~LambdaHolder() { !LambdaHolder(); }
public:
	TRet Callback(TParams... params) { return (*m_func)(params...); }
	operator TDelegate ^ () { return gcnew TDelegate(this, &LambdaHolder::Callback); }
private:
	TLambda * m_func;
};

template<typename TLambda, typename TRet, typename ...TParams>
ref class LambdaHolder<AutoDetectDelegateType, TLambda, TRet, TParams...>
{
public:
	inline LambdaHolder(const TLambda % func) { m_func = new TLambda(func); }
	!LambdaHolder() { delete m_func; }
	~LambdaHolder() { !LambdaHolder(); }
public:
	TRet Callback(TParams... params) { return (*m_func)(params...); }
	template<typename TDelegate>
	operator TDelegate ^ () { return gcnew TDelegate(this, &LambdaHolder::Callback); }
private:
	TLambda * m_func;
};

template <typename TDelegate, typename TLambda>
struct get_labmda_holder : public get_labmda_holder < TDelegate, decltype(&TLambda::operator()) > {};

template <typename TDelegate, typename TLambda, typename TRet, typename... TParams>
struct get_labmda_holder < TDelegate, TRet(__clrcall TLambda::*)(TParams...) const >
{
	typedef LambdaHolder<TDelegate, TLambda, TRet, TParams...> TLambdaHolder;
};

template <typename TDelegate, typename TLambda, typename TRet, typename... TParams>
struct get_labmda_holder < TDelegate, TRet(__clrcall TLambda::*)(TParams...) >
{
	typedef LambdaHolder<TDelegate, TLambda, TRet, TParams...> TLambdaHolder;
};

template <typename TDelegate, typename TLambda, typename TRet, typename... TParams>
struct get_labmda_holder < TDelegate, TRet(__thiscall TLambda::*)(TParams...) const >
{
	typedef LambdaHolder<TDelegate, TLambda, TRet, TParams...> TLambdaHolder;
};

template <typename TDelegate, typename TLambda, typename TRet, typename... TParams>
struct get_labmda_holder < TDelegate, TRet(__thiscall TLambda::*)(TParams...)>
{
	typedef LambdaHolder<TDelegate, TLambda, TRet, TParams...> TLambdaHolder;
};

template<typename TDelegate = AutoDetectDelegateType>
struct Lambda2Delegate
{
	template<typename TLambda>
	typename get_labmda_holder<TDelegate, TLambda>::TLambdaHolder ^ operator = (const TLambda % func)
	{
		return gcnew get_labmda_holder<TDelegate, TLambda>::TLambdaHolder(func);
	}
};

#endif