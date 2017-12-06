#pragma once

#include "Node.h"
#include "Math/IPositionAdapter.h"
#include "IIterator.h"
#include "Path.h"

namespace Moge
{
    class MogeLib_API INodeFactory
    {
    public:
        INodeFactory()
        {
        }

        virtual ~INodeFactory()
        {
        }
        
        virtual std::shared_ptr<Node> CreateFromImage(
            const Path& filePath, 
            const MyString& name = MyString( "" ) ) = 0;
        
        virtual std::shared_ptr<Node> createFromTexture(
            const std::shared_ptr<ITexture>& texture, 
            const MyString& name = MyString( "" ) ) = 0;
        
        virtual void remove( const std::shared_ptr<Node>& node) = 0;
        virtual void remove( const Node* node ) = 0;
        virtual const bool exist(const std::shared_ptr<Node>& node ) const = 0;
        virtual const unsigned int count() const = 0;
        virtual IIterator<std::shared_ptr<Node>>& getNodes() = 0;
    protected:
    private:
    };
}
