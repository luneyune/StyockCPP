
class iCommand
{
public:
    virtual Command() = 0;
    virtual Command(int *args, size_t argsCount) = 0;
    virtual ~Command() = 0;

    virtual void execute() = 0;
}