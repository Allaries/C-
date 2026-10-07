template <typename T>
void swap(T &s1, T &s2)
{
	T temp = s1;
	s1 = s2;
	s2 = temp;
	return ;
}

template <typename T>
T	min(T s1, T s2)
{
	if (s1 == s2)
		return (s2);
	if (s1 < s2)
		return (s1);
	else
		return (s2);
}

template <typename T>
T	max(T s1, T s2)
{
	if (s1 == s2)
		return (s2);
	if (s1 > s2)
		return (s1);
	else
		return (s2);
}