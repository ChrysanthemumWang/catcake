/*
    Copyright (c) 2007-2009 Takashi Kitao
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
    `  notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
    `  notice, this list of conditions and the following disclaimer in the
    `  documentation and/or other materials provided with the distribution.

    3. The name of the author may not be used to endorse or promote products
    `  derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
    OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
    IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
    NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
    THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


class ckRend_Light;


/*!
    @ingroup ckDraw
    TODO
*/
class CK_API ckMdl
{
public:
    ckDefineException(ExceptionInvalidArgument);
    ckDefineException(ExceptionNotInitialized);

    ckMdl();
    ~ckMdl();

    void init(ckID mdl_data_id, ckID scr_id);
    void init(ckID mdl_data_id, ckDraw* parent);

    const ckMdlData* getModelData() const;

    ckID getTextureID() const;
    void setTextureID(ckID tex_id);

    ckID getLightSetID() const;
    void setLightSetID(ckID lts_id);

    ckDraw* getRootDraw();
    ckDraw* getNodeDraw(u16 node_index);

private:
    ckMdl(const ckMdl&);
    void operator=(const ckMdl&);

    void init2(ckID mdl_data_id, ckID scr_id, ckDraw* parent);
    void uninit();

    ckMdlData m_mdl_data;
    ckDraw** m_draw_ptr;
    ckRend_Light** m_rend_ptr;
    ckNode m_root_node;
    u16 m_node_num;
    ckID m_lts_id;
};