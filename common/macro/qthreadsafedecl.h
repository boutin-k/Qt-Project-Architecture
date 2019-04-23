#ifndef QTHREADSAFEDECL_H
#define QTHREADSAFEDECL_H

// @brief Thread safe variable accessors declaration
// @param NAME Variable name
// @param TYPE Variable type
// @param DATA_ID Id of the plugin data
#define SHARED_DATA(NAME, TYPE, DATA_ID)        \
    public slots:                               \
        void set_##NAME(TYPE value) {           \
            this->m_##NAME = value;             \
            emit setSharedData(DATA_ID, value); \
        }                                       \
    public:                                     \
        TYPE get_##NAME() const {               \
            return m_##NAME;                    \
        }                                       \
    private:                                    \
        TYPE m_##NAME;


#endif // QTHREADSAFEDECL_H
